#include "tree_sitter/parser.h"
#include <wctype.h>

enum TokenType {
  PREPROC_NAME_OPENING,
  PREPROC_NAME_ENDING,

  PREPROC_EXPR_OPENING,
  PREPROC_EXPR_ENDING,

  PREPROC_INLINE_CONTENT,

  BLOCK_STRING_OPENING,
  BLOCK_STRING_ENDING,
  BLOCK_STRING_CONTENT,

  BLOCK_COMMENT_OPENING,
  BLOCK_COMMENT_ENDING,
  BLOCK_COMMENT_CONTENT,

  BLOCK_PREPROC_OPENING,
  BLOCK_PREPROC_ENDING,
  BLOCK_PREPROC_CONTENT,
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
static inline bool consume_check(TSLexer *lex, int32_t ch) {
  bool valid = lex->lookahead == ch;
  if (valid)
    consume(lex);
  return valid;
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
  if (consume_check(lex, '#') && lex->lookahead == opening) {
    preproc_ending = opening == '[' ? ']' : '|';
    consume(lex);
    return true;
  }

  return false;
}

static bool scan_preproc_inline_ending(TSLexer *lex, char ending) {
  if (preproc_ending == 0)
    return false;

  if ((ending != 0
           ? consume_check(lex, preproc_ending) && preproc_ending == ending
           : consume_check(lex, ']') || consume_check(lex, '|')) &&
      lex->lookahead == '#') {
    consume(lex);
    return true;
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
  if (consume_check(lex, '-') && consume_check(lex, '-') && scan_block_opening(lex)) {
    return true;
  }
  
  return false;
}

static bool scan_block_preproc_opening(TSLexer* lex) {
  if (consume_check(lex, '#') && consume_check(lex, '#') && scan_block_opening(lex)) {
    return true;
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

  if (valid_symbols[BLOCK_STRING_ENDING] && scan_block_ending(lex)) {
    reset_state();
    lex->result_symbol = BLOCK_STRING_ENDING;
    return true;
  }

  if (valid_symbols[BLOCK_COMMENT_ENDING] && scan_block_ending(lex)) {
    reset_state();
    lex->result_symbol = BLOCK_COMMENT_ENDING;
    return true;
  }

  if (valid_symbols[BLOCK_PREPROC_ENDING] && scan_block_ending(lex)) {
    reset_state();
    lex->result_symbol = BLOCK_PREPROC_ENDING;
    return true;
  }

  if (valid_symbols[PREPROC_INLINE_CONTENT] &&
      scan_preproc_inline_content(lex)) {
    lex->result_symbol = PREPROC_INLINE_CONTENT;
    return true;
  }

  if (valid_symbols[BLOCK_STRING_CONTENT] && scan_block_content(lex)) {
    lex->result_symbol = BLOCK_STRING_CONTENT;
    return true;
  }

  if (valid_symbols[BLOCK_COMMENT_CONTENT] && scan_block_content(lex)) {
    lex->result_symbol = BLOCK_COMMENT_CONTENT;
    return true;
  }

  if (valid_symbols[BLOCK_PREPROC_CONTENT] && scan_block_content(lex)) {
    lex->result_symbol = BLOCK_PREPROC_CONTENT;
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

  if (valid_symbols[BLOCK_STRING_OPENING] && scan_block_opening(lex)) {
    lex->result_symbol = BLOCK_STRING_OPENING;
    return true;
  }

  if (valid_symbols[BLOCK_COMMENT_OPENING] && scan_block_comment_opening(lex)) {
    lex->result_symbol = BLOCK_COMMENT_OPENING;
    return true;
  }

  if (valid_symbols[BLOCK_PREPROC_OPENING] && scan_block_preproc_opening(lex)) {
    lex->result_symbol = BLOCK_PREPROC_OPENING;
    return true;
  }

  return false;
}
