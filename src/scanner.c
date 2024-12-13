#include "tree_sitter/parser.h"

enum TokenType {
  START_PREPROC_NAME,
  CONTENT_PREPROC_NAME,
  END_PREPROC_NAME,

  START_PREPROC_EXPR,
  CONTENT_PREPROC_EXPR,
  END_PREPROC_EXPR,
};

void *tree_sitter_nelua_external_scanner_create() { return NULL; }
void tree_sitter_nelua_external_scanner_destroy(void *payload) {}

unsigned tree_sitter_nelua_external_scanner_serialize(void *payload,
                                                      char *buffer) {
  return 0;
}
void tree_sitter_nelua_external_scanner_deserialize(void *payload,
                                                    const char *buffer,
                                                    unsigned length) {}
