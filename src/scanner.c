#include "tree_sitter/parser.h"
#include <wctype.h>

enum TokenType {
  START_PREPROC_NAME,
  START_PREPROC_EXPR,
  CONTENT_PREPROC_INLINE,
  END_PREPROC_NAME,
  END_PREPROC_EXPR,
};

static inline void consume(TSLexer *lex) { lex->advance(lex, false); }
static inline void skip(TSLexer *lex) { lex->advance(lex, true); }

char preproc_start = 0;
char preproc_end = 0;

static inline void reset_state() {
  preproc_start = 0;
  preproc_end = 0;
}

static inline void skip_whitespaces(TSLexer *lexer) {
  while (iswspace(lexer->lookahead)) {
    skip(lexer);
  }
}

static bool start_end_pair(TSLexer *lex) {
  if (preproc_start == '[' && lex->lookahead == preproc_end ||
      preproc_start == '|') {
    consume(lex);
    return true;
  }
  return false;
}

static bool scan_preproc_inline_start(TSLexer *lex) {
  if (lex->lookahead == '#') {
    consume(lex);
    if (lex->lookahead == '|' || lex->lookahead == '[') {
      preproc_start = lex->lookahead;
      preproc_end = lex->lookahead == '[' ? ']' : '|';
      consume(lex);
      return true;
    }
  }

  return false;
}

static bool scan_preproc_inline_end(TSLexer *lex) {
  if (preproc_end == 0)
    return false;

  if (start_end_pair(lex) && lex->lookahead == '#') {
    consume(lex);
    return true;
  }

  return false;
}

static bool scan_preproc_inline_content(TSLexer *lex) {
  while (lex->lookahead != 0) {
    consume(lex);
    if (lex->lookahead == preproc_end) {
      return true;
    }
  }

  return false;
}

void *tree_sitter_nelua_external_scanner_create() { return NULL; }
void tree_sitter_nelua_external_scanner_destroy(void *payload) {}

unsigned tree_sitter_nelua_external_scanner_serialize(void *payload,
                                                      char *buffer) {
  buffer[0] = preproc_start;
  buffer[1] = preproc_end;
  return 2;
}
void tree_sitter_nelua_external_scanner_deserialize(void *payload,
                                                    const char *buffer,
                                                    unsigned length) {
  if (length == 0)
    return;
  preproc_start = buffer[0];
  if (length == 1)
    return;
  preproc_end = buffer[1];
}

bool tree_sitter_nelua_external_scanner_scan(void *payload, TSLexer *lex,
                                             const bool *valid_symbols) {
  if (valid_symbols[END_PREPROC_NAME] && preproc_end == '|' && scan_preproc_inline_end(lex)) {
    reset_state();
    lex->result_symbol = END_PREPROC_NAME;
    lex->mark_end(lex);
    return true;
  }

  if (valid_symbols[END_PREPROC_EXPR] && preproc_end == ']' && scan_preproc_inline_end(lex)) {
    reset_state();
    lex->result_symbol = END_PREPROC_EXPR;
    lex->mark_end(lex);
    return true;
  }
  
  if (valid_symbols[CONTENT_PREPROC_INLINE] &&
      scan_preproc_inline_content(lex)) {
    lex->result_symbol = CONTENT_PREPROC_INLINE;
    lex->mark_end(lex);
    return true;
  }

  skip_whitespaces(lex);

  if (valid_symbols[START_PREPROC_NAME] && scan_preproc_inline_start(lex) && preproc_start == '|') {
    lex->result_symbol = START_PREPROC_NAME;
    lex->mark_end(lex);
    return true;
  }

  if (valid_symbols[START_PREPROC_EXPR] && scan_preproc_inline_start(lex) && preproc_start == ']') {
    lex->result_symbol = START_PREPROC_EXPR;
    lex->mark_end(lex);
    return true;
  }

  return false;
}
