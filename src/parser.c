#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 6
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 17
#define ALIAS_COUNT 0
#define TOKEN_COUNT 13
#define EXTERNAL_TOKEN_COUNT 5
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 1
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  sym_nil_literal = 1,
  sym_nilptr_literal = 2,
  anon_sym_true = 3,
  anon_sym_false = 4,
  sym_varargs = 5,
  sym_number = 6,
  sym__identifier = 7,
  sym__start_preproc_name = 8,
  sym__start_preproc_expr = 9,
  sym__content_preproc_inline = 10,
  sym__end_preproc_name = 11,
  sym__end_preproc_expr = 12,
  sym_chunk = 13,
  sym__expressions = 14,
  sym_boolean_literal = 15,
  sym_identifier = 16,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_nil_literal] = "nil_literal",
  [sym_nilptr_literal] = "nilptr_literal",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [sym_varargs] = "varargs",
  [sym_number] = "number",
  [sym__identifier] = "_identifier",
  [sym__start_preproc_name] = "_start_preproc_name",
  [sym__start_preproc_expr] = "_start_preproc_expr",
  [sym__content_preproc_inline] = "_content_preproc_inline",
  [sym__end_preproc_name] = "_end_preproc_name",
  [sym__end_preproc_expr] = "_end_preproc_expr",
  [sym_chunk] = "chunk",
  [sym__expressions] = "_expressions",
  [sym_boolean_literal] = "boolean_literal",
  [sym_identifier] = "identifier",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_nil_literal] = sym_nil_literal,
  [sym_nilptr_literal] = sym_nilptr_literal,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [sym_varargs] = sym_varargs,
  [sym_number] = sym_number,
  [sym__identifier] = sym__identifier,
  [sym__start_preproc_name] = sym__start_preproc_name,
  [sym__start_preproc_expr] = sym__start_preproc_expr,
  [sym__content_preproc_inline] = sym__content_preproc_inline,
  [sym__end_preproc_name] = sym__end_preproc_name,
  [sym__end_preproc_expr] = sym__end_preproc_expr,
  [sym_chunk] = sym_chunk,
  [sym__expressions] = sym__expressions,
  [sym_boolean_literal] = sym_boolean_literal,
  [sym_identifier] = sym_identifier,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_nil_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_nilptr_literal] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_true] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_false] = {
    .visible = true,
    .named = false,
  },
  [sym_varargs] = {
    .visible = true,
    .named = true,
  },
  [sym_number] = {
    .visible = true,
    .named = true,
  },
  [sym__identifier] = {
    .visible = false,
    .named = true,
  },
  [sym__start_preproc_name] = {
    .visible = false,
    .named = true,
  },
  [sym__start_preproc_expr] = {
    .visible = false,
    .named = true,
  },
  [sym__content_preproc_inline] = {
    .visible = false,
    .named = true,
  },
  [sym__end_preproc_name] = {
    .visible = false,
    .named = true,
  },
  [sym__end_preproc_expr] = {
    .visible = false,
    .named = true,
  },
  [sym_chunk] = {
    .visible = true,
    .named = true,
  },
  [sym__expressions] = {
    .visible = false,
    .named = true,
  },
  [sym_boolean_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(5);
      if (lookahead == '.') ADVANCE(1);
      if (lookahead == 'f') ADVANCE(14);
      if (lookahead == 'n') ADVANCE(17);
      if (lookahead == 't') ADVANCE(20);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(11);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(25);
      END_STATE();
    case 1:
      if (lookahead == '.') ADVANCE(2);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(12);
      END_STATE();
    case 2:
      if (lookahead == '.') ADVANCE(10);
      END_STATE();
    case 3:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(4);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(13);
      END_STATE();
    case 4:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(13);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(sym_nil_literal);
      if (lookahead == 'p') ADVANCE(23);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(25);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(sym_nilptr_literal);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(25);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(anon_sym_true);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(25);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(anon_sym_false);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(25);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(sym_varargs);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '.') ADVANCE(12);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(3);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(11);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(3);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(12);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(13);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(sym__identifier);
      if (lookahead == 'a') ADVANCE(18);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(25);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(sym__identifier);
      if (lookahead == 'e') ADVANCE(8);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(25);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(sym__identifier);
      if (lookahead == 'e') ADVANCE(9);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(25);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(sym__identifier);
      if (lookahead == 'i') ADVANCE(19);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(25);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(sym__identifier);
      if (lookahead == 'l') ADVANCE(22);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(25);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(sym__identifier);
      if (lookahead == 'l') ADVANCE(6);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(25);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(sym__identifier);
      if (lookahead == 'r') ADVANCE(24);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(25);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(sym__identifier);
      if (lookahead == 'r') ADVANCE(7);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(25);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(sym__identifier);
      if (lookahead == 's') ADVANCE(16);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(25);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(sym__identifier);
      if (lookahead == 't') ADVANCE(21);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(25);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(sym__identifier);
      if (lookahead == 'u') ADVANCE(15);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(25);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(sym__identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(25);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_nil_literal] = ACTIONS(1),
    [sym_nilptr_literal] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [sym_varargs] = ACTIONS(1),
    [sym_number] = ACTIONS(1),
    [sym__identifier] = ACTIONS(1),
    [sym__start_preproc_name] = ACTIONS(1),
    [sym__start_preproc_expr] = ACTIONS(1),
    [sym__content_preproc_inline] = ACTIONS(1),
    [sym__end_preproc_name] = ACTIONS(1),
    [sym__end_preproc_expr] = ACTIONS(1),
  },
  [1] = {
    [sym_chunk] = STATE(4),
    [sym__expressions] = STATE(5),
    [sym_boolean_literal] = STATE(5),
    [sym_identifier] = STATE(5),
    [sym_nil_literal] = ACTIONS(3),
    [sym_nilptr_literal] = ACTIONS(3),
    [anon_sym_true] = ACTIONS(5),
    [anon_sym_false] = ACTIONS(5),
    [sym_varargs] = ACTIONS(7),
    [sym_number] = ACTIONS(7),
    [sym__identifier] = ACTIONS(9),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 1,
    ACTIONS(11), 1,
      ts_builtin_sym_end,
  [4] = 1,
    ACTIONS(13), 1,
      ts_builtin_sym_end,
  [8] = 1,
    ACTIONS(15), 1,
      ts_builtin_sym_end,
  [12] = 1,
    ACTIONS(17), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 4,
  [SMALL_STATE(4)] = 8,
  [SMALL_STATE(5)] = 12,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean_literal, 1, 0, 0),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier, 1, 0, 0),
  [15] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chunk, 1, 0, 0),
};

enum ts_external_scanner_symbol_identifiers {
  ts_external_token__start_preproc_name = 0,
  ts_external_token__start_preproc_expr = 1,
  ts_external_token__content_preproc_inline = 2,
  ts_external_token__end_preproc_name = 3,
  ts_external_token__end_preproc_expr = 4,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token__start_preproc_name] = sym__start_preproc_name,
  [ts_external_token__start_preproc_expr] = sym__start_preproc_expr,
  [ts_external_token__content_preproc_inline] = sym__content_preproc_inline,
  [ts_external_token__end_preproc_name] = sym__end_preproc_name,
  [ts_external_token__end_preproc_expr] = sym__end_preproc_expr,
};

static const bool ts_external_scanner_states[2][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__start_preproc_name] = true,
    [ts_external_token__start_preproc_expr] = true,
    [ts_external_token__content_preproc_inline] = true,
    [ts_external_token__end_preproc_name] = true,
    [ts_external_token__end_preproc_expr] = true,
  },
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_nelua_external_scanner_create(void);
void tree_sitter_nelua_external_scanner_destroy(void *);
bool tree_sitter_nelua_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_nelua_external_scanner_serialize(void *, char *);
void tree_sitter_nelua_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_nelua(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_nelua_external_scanner_create,
      tree_sitter_nelua_external_scanner_destroy,
      tree_sitter_nelua_external_scanner_scan,
      tree_sitter_nelua_external_scanner_serialize,
      tree_sitter_nelua_external_scanner_deserialize,
    },
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
