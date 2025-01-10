#include "tree_sitter/parser.h"
#include <wctype.h>

enum TokenType {
  PREPROC_NAME_OPENING,
  PREPROC_NAME_ENDING,

  PREPROC_EXPR_OPENING,
  PREPROC_EXPR_ENDING,

  PREPROC_INLINE_CONTENT,

  STRING_OPENING,
  STRING_ENDING,
  STRING_CONTENT,

  BLOCK_COMMENT_OPENING,
  BLOCK_COMMENT_ENDING,
  BLOCK_COMMENT_CONTENT,
};

enum PreprocEndingType {
  PREPROC_ENDING_INVALID = 0,
  PREPROC_ENDING_NAME,
  PREPROC_ENDING_EXPR,
};

static inline void consume(TSLexer *lex) { lex->advance(lex, false); }
static inline uint64_t consume_length(TSLexer *lex, int32_t ch) {
  uint64_t length;
  for (length = 0; lex->lookahead == ch; length++) {
    consume(lex);
  }
  return length;
}
static inline void skip(TSLexer *lex) { lex->advance(lex, true); }

#define log(a, b, ...) a->log(a, "[tree-sitter-nelua] " b, __VA_ARGS__)
#define string(a)                                                              \
  (char[1]) { a }

char preproc_ending = 0;
char string_ending = 0;
uint64_t block_length = 0;

static inline void reset_state() {
  preproc_ending = 0;
  string_ending = 0;
  block_length = 0;
}

static inline void skip_whitespaces(TSLexer *lexer) {
  while (true) {
    if (!iswspace(lexer->lookahead)) {
      break;
    }
    skip(lexer);
  }
}

void *tree_sitter_nelua_external_scanner_create() { return NULL; }
void tree_sitter_nelua_external_scanner_destroy(void *payload) {}

unsigned tree_sitter_nelua_external_scanner_serialize(void *payload,
                                                      char *buffer) {
  buffer[0] = preproc_ending;
  buffer[1] = block_length;
  buffer[2] = string_ending;
  return 3;
}
void tree_sitter_nelua_external_scanner_deserialize(void *payload,
                                                    const char *buffer,
                                                    unsigned length) {
  if (length == 0)
    return;
  preproc_ending = buffer[0];
  if (length == 1)
    return;
  block_length = buffer[1];
  if (length == 2)
    return;
  string_ending = buffer[2];
}

static bool scan_preproc_inline_opening(TSLexer *lex, char opening) {
  if (lex->lookahead == '#') {
    consume(lex);
    if (lex->lookahead == opening) {
      preproc_ending = opening == '[' ? ']' : '|';
      consume(lex);
      return true;
    }
  }

  return false;
}

static bool scan_preproc_inline_ending(TSLexer *lex, char ending) {
  if (preproc_ending == 0)
    return false;

  if (ending != 0 ? lex->lookahead == preproc_ending && preproc_ending == ending
                  : lex->lookahead == ']' || lex->lookahead == '|') {
    consume(lex);
    if (lex->lookahead == '#') {
      consume(lex);
      return true;
    }
  }

  return false;
}

static bool scan_preproc_inline_content(TSLexer *lex) {
  while (lex->lookahead != 0) {
    if (lex->lookahead == preproc_ending) {
      lex->mark_end(lex);
      if (scan_preproc_inline_ending(lex, 0)) {
        return true;
      }
    } else {
      consume(lex);
    }
  }

  return false;
}

static bool scan_block_opening(TSLexer *lex) {
  if (lex->lookahead != '[')
    return false;
  consume(lex);

  block_length = consume_length(lex, '=');
  log(lex, "block length: %d", block_length);

  if (lex->lookahead != '[')
    return false;
  consume(lex);

  return true;
}

static bool scan_block_ending(TSLexer *lex) {
  if (lex->lookahead != ']')
    return false;
  consume(lex);

  if (consume_length(lex, '=') != block_length)
    return false;

  if (lex->lookahead != ']')
    return false;
  consume(lex);

  return true;
}

static bool scan_block_content(TSLexer *lex) {
  while (lex->lookahead != 0) {
    if (lex->lookahead == ']') {
      lex->mark_end(lex);
      if (scan_block_ending(lex)) {
        return true;
      }
    } else {
      consume(lex);
    }
  }

  return false;
}

static bool scan_block_comment_opening(TSLexer *lex) {
  if (lex->lookahead != '-')
    return false;
  consume(lex);

  if (lex->lookahead != '-')
    return false;
  consume(lex);

  return scan_block_opening(lex);
}

static bool scan_string_opening(TSLexer *lex) {
  if (lex->lookahead == '[') {
    return scan_block_opening(lex);
  }

  if (lex->lookahead == '\'' || lex->lookahead == '"') {
    string_ending = lex->lookahead;
    consume(lex);
    return true;
  }
  return false;
}

static bool scan_string_ending(TSLexer *lex) {
  if (lex->lookahead == ']')
    return scan_block_ending(lex);

  if (string_ending != 0 || lex->lookahead == string_ending) {
    consume(lex);
    return true;
  }

  return false;
}

static bool scan_string_content(TSLexer *lex) {
  if (string_ending == 0)
    return scan_block_content(lex);

  while (lex->lookahead != 0) {
    if (lex->lookahead == string_ending) {
      return true;
    }

    if (lex->lookahead == '\\') {
      consume(lex);
      if (lex->lookahead == 'z') {
        consume(lex);
        while (iswspace(lex->lookahead)) {
          consume(lex);
        }
        continue;
      } else if (lex->lookahead == '\n') {
        consume(lex);
        continue;
      }
    }

    if (lex->lookahead == '\n') {
      return false;
    }

    consume(lex);
  }

  return false;
}

bool tree_sitter_nelua_external_scanner_scan(void *payload, TSLexer *lex,
                                             const bool *valid_symbols) {
  if (valid_symbols[PREPROC_EXPR_ENDING] &&
      scan_preproc_inline_ending(lex, ']')) {
    reset_state();
    lex->result_symbol = PREPROC_EXPR_ENDING;
    return true;
  }

  if (valid_symbols[PREPROC_NAME_ENDING] &&
      scan_preproc_inline_ending(lex, '|')) {
    reset_state();
    lex->result_symbol = PREPROC_NAME_ENDING;
    return true;
  }

  if (valid_symbols[STRING_ENDING] && scan_string_ending(lex)) {
    reset_state();
    lex->result_symbol = STRING_ENDING;
    return true;
  }

  if (valid_symbols[BLOCK_COMMENT_ENDING] && scan_block_ending(lex)) {
    reset_state();
    lex->result_symbol = BLOCK_COMMENT_ENDING;
    return true;
  }

  if (valid_symbols[PREPROC_INLINE_CONTENT] &&
      scan_preproc_inline_content(lex)) {
    lex->result_symbol = PREPROC_INLINE_CONTENT;
    return true;
  }

  if (valid_symbols[STRING_CONTENT] && scan_string_content(lex)) {
    lex->result_symbol = STRING_CONTENT;
    return true;
  }

  if (valid_symbols[BLOCK_COMMENT_CONTENT] && scan_block_content(lex)) {
    lex->result_symbol = BLOCK_COMMENT_CONTENT;
    return true;
  }

  skip_whitespaces(lex);

  if (valid_symbols[PREPROC_EXPR_OPENING] &&
      scan_preproc_inline_opening(lex, '[')) {
    lex->result_symbol = PREPROC_EXPR_OPENING;
    return true;
  }

  if (valid_symbols[PREPROC_NAME_OPENING] &&
      scan_preproc_inline_opening(lex, '|')) {
    lex->result_symbol = PREPROC_NAME_OPENING;
    return true;
  }

  if (valid_symbols[STRING_OPENING] && scan_string_opening(lex)) {
    lex->result_symbol = STRING_OPENING;
    return true;
  }

  if (valid_symbols[BLOCK_COMMENT_OPENING] && scan_block_comment_opening(lex)) {
    lex->result_symbol = BLOCK_COMMENT_OPENING;
    return true;
  }

  return false;
}
