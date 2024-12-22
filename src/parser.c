#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 40
#define LARGE_STATE_COUNT 6
#define SYMBOL_COUNT 34
#define ALIAS_COUNT 0
#define TOKEN_COUNT 20
#define EXTERNAL_TOKEN_COUNT 5
#define FIELD_COUNT 2
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 6

enum ts_symbol_identifiers {
  sym_nil_literal = 1,
  sym_nilptr_literal = 2,
  anon_sym_true = 3,
  anon_sym_false = 4,
  sym_varargs = 5,
  aux_sym_number_token1 = 6,
  anon_sym_LBRACE = 7,
  anon_sym_RBRACE = 8,
  anon_sym_COMMA = 9,
  anon_sym_SEMI = 10,
  anon_sym_EQ = 11,
  anon_sym_LBRACK = 12,
  anon_sym_RBRACK = 13,
  sym__identifier = 14,
  sym__start_preproc_name = 15,
  sym__start_preproc_expr = 16,
  sym__content_preproc_inline = 17,
  sym__end_preproc_name = 18,
  sym__end_preproc_expr = 19,
  sym_chunk = 20,
  sym__expression = 21,
  sym_boolean_literal = 22,
  sym_number = 23,
  sym_table_constructor = 24,
  sym_field_list = 25,
  sym_field_separator = 26,
  sym_field_expression = 27,
  sym__field_sugar_pair = 28,
  sym__field_pair = 29,
  sym_identifier = 30,
  sym__preprocess_name = 31,
  sym_preprocess_expr = 32,
  aux_sym_field_list_repeat1 = 33,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_nil_literal] = "nil_literal",
  [sym_nilptr_literal] = "nilptr_literal",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [sym_varargs] = "varargs",
  [aux_sym_number_token1] = "number_token1",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_COMMA] = ",",
  [anon_sym_SEMI] = ";",
  [anon_sym_EQ] = "=",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [sym__identifier] = "_identifier",
  [sym__start_preproc_name] = "_start_preproc_name",
  [sym__start_preproc_expr] = "_start_preproc_expr",
  [sym__content_preproc_inline] = "lua_expression",
  [sym__end_preproc_name] = "_end_preproc_name",
  [sym__end_preproc_expr] = "_end_preproc_expr",
  [sym_chunk] = "chunk",
  [sym__expression] = "_expression",
  [sym_boolean_literal] = "boolean_literal",
  [sym_number] = "number",
  [sym_table_constructor] = "table_constructor",
  [sym_field_list] = "field_list",
  [sym_field_separator] = "field_separator",
  [sym_field_expression] = "field_expression",
  [sym__field_sugar_pair] = "_field_sugar_pair",
  [sym__field_pair] = "_field_pair",
  [sym_identifier] = "identifier",
  [sym__preprocess_name] = "_preprocess_name",
  [sym_preprocess_expr] = "preprocess_expr",
  [aux_sym_field_list_repeat1] = "field_list_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_nil_literal] = sym_nil_literal,
  [sym_nilptr_literal] = sym_nilptr_literal,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [sym_varargs] = sym_varargs,
  [aux_sym_number_token1] = aux_sym_number_token1,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [sym__identifier] = sym__identifier,
  [sym__start_preproc_name] = sym__start_preproc_name,
  [sym__start_preproc_expr] = sym__start_preproc_expr,
  [sym__content_preproc_inline] = sym__content_preproc_inline,
  [sym__end_preproc_name] = sym__end_preproc_name,
  [sym__end_preproc_expr] = sym__end_preproc_expr,
  [sym_chunk] = sym_chunk,
  [sym__expression] = sym__expression,
  [sym_boolean_literal] = sym_boolean_literal,
  [sym_number] = sym_number,
  [sym_table_constructor] = sym_table_constructor,
  [sym_field_list] = sym_field_list,
  [sym_field_separator] = sym_field_separator,
  [sym_field_expression] = sym_field_expression,
  [sym__field_sugar_pair] = sym__field_sugar_pair,
  [sym__field_pair] = sym__field_pair,
  [sym_identifier] = sym_identifier,
  [sym__preprocess_name] = sym__preprocess_name,
  [sym_preprocess_expr] = sym_preprocess_expr,
  [aux_sym_field_list_repeat1] = aux_sym_field_list_repeat1,
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
  [aux_sym_number_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
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
    .visible = true,
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
  [sym__expression] = {
    .visible = false,
    .named = true,
  },
  [sym_boolean_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_number] = {
    .visible = true,
    .named = true,
  },
  [sym_table_constructor] = {
    .visible = true,
    .named = true,
  },
  [sym_field_list] = {
    .visible = true,
    .named = true,
  },
  [sym_field_separator] = {
    .visible = true,
    .named = true,
  },
  [sym_field_expression] = {
    .visible = true,
    .named = true,
  },
  [sym__field_sugar_pair] = {
    .visible = false,
    .named = true,
  },
  [sym__field_pair] = {
    .visible = false,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym__preprocess_name] = {
    .visible = false,
    .named = true,
  },
  [sym_preprocess_expr] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_field_list_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_key = 1,
  field_value = 2,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_key] = "key",
  [field_value] = "value",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 2},
  [4] = {.index = 4, .length = 2},
  [5] = {.index = 6, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_value, 0},
  [1] =
    {field_key, 0},
  [2] =
    {field_key, 0, .inherited = true},
    {field_value, 0, .inherited = true},
  [4] =
    {field_key, 0},
    {field_value, 2},
  [6] =
    {field_key, 1},
    {field_value, 4},
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
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 20,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(10);
      ADVANCE_MAP(
        ',', 26,
        '.', 1,
        '0', 16,
        ';', 27,
        '=', 28,
        '[', 29,
        ']', 30,
        'f', 31,
        'n', 34,
        't', 37,
        '{', 24,
        '}', 25,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(17);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(42);
      END_STATE();
    case 1:
      if (lookahead == '.') ADVANCE(2);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(20);
      END_STATE();
    case 2:
      if (lookahead == '.') ADVANCE(15);
      END_STATE();
    case 3:
      if (lookahead == '.') ADVANCE(6);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(18);
      END_STATE();
    case 4:
      if (lookahead == '.') ADVANCE(8);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(19);
      END_STATE();
    case 5:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(7);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(23);
      END_STATE();
    case 6:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(21);
      END_STATE();
    case 7:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(23);
      END_STATE();
    case 8:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(22);
      END_STATE();
    case 9:
      if (eof) ADVANCE(10);
      if (lookahead == ',') ADVANCE(26);
      if (lookahead == ';') ADVANCE(27);
      if (lookahead == ']') ADVANCE(30);
      if (lookahead == '}') ADVANCE(25);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(9);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(42);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(sym_nil_literal);
      if (lookahead == 'p') ADVANCE(40);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(42);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(sym_nilptr_literal);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(42);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(anon_sym_true);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(42);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(anon_sym_false);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(42);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(sym_varargs);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == '.') ADVANCE(20);
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(3);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(5);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(4);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(17);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == '.') ADVANCE(20);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(5);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(17);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == '.') ADVANCE(21);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(5);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(18);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == '.') ADVANCE(22);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(5);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(19);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(5);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(20);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(5);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(21);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(5);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(22);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(23);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym__identifier);
      if (lookahead == 'a') ADVANCE(35);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(42);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym__identifier);
      if (lookahead == 'e') ADVANCE(13);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(42);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym__identifier);
      if (lookahead == 'e') ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(42);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym__identifier);
      if (lookahead == 'i') ADVANCE(36);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(42);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym__identifier);
      if (lookahead == 'l') ADVANCE(39);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(42);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym__identifier);
      if (lookahead == 'l') ADVANCE(11);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(42);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym__identifier);
      if (lookahead == 'r') ADVANCE(41);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(42);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym__identifier);
      if (lookahead == 'r') ADVANCE(12);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(42);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym__identifier);
      if (lookahead == 's') ADVANCE(33);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(42);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym__identifier);
      if (lookahead == 't') ADVANCE(38);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(42);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym__identifier);
      if (lookahead == 'u') ADVANCE(32);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(42);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym__identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(42);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 0, .external_lex_state = 2},
  [2] = {.lex_state = 0, .external_lex_state = 2},
  [3] = {.lex_state = 0, .external_lex_state = 2},
  [4] = {.lex_state = 0, .external_lex_state = 2},
  [5] = {.lex_state = 0, .external_lex_state = 2},
  [6] = {.lex_state = 0, .external_lex_state = 2},
  [7] = {.lex_state = 0, .external_lex_state = 2},
  [8] = {.lex_state = 0, .external_lex_state = 2},
  [9] = {.lex_state = 0, .external_lex_state = 2},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 9},
  [21] = {.lex_state = 9, .external_lex_state = 3},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 9},
  [31] = {.lex_state = 0, .external_lex_state = 4},
  [32] = {.lex_state = 0, .external_lex_state = 4},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0, .external_lex_state = 5},
  [39] = {.lex_state = 0, .external_lex_state = 6},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_nil_literal] = ACTIONS(1),
    [sym_nilptr_literal] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [sym_varargs] = ACTIONS(1),
    [aux_sym_number_token1] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [sym__identifier] = ACTIONS(1),
    [sym__start_preproc_name] = ACTIONS(1),
    [sym__start_preproc_expr] = ACTIONS(1),
    [sym__content_preproc_inline] = ACTIONS(1),
    [sym__end_preproc_name] = ACTIONS(1),
    [sym__end_preproc_expr] = ACTIONS(1),
  },
  [1] = {
    [sym_chunk] = STATE(37),
    [sym__expression] = STATE(35),
    [sym_boolean_literal] = STATE(35),
    [sym_number] = STATE(35),
    [sym_table_constructor] = STATE(35),
    [sym_identifier] = STATE(35),
    [sym__preprocess_name] = STATE(10),
    [sym_preprocess_expr] = STATE(35),
    [sym_nil_literal] = ACTIONS(3),
    [sym_nilptr_literal] = ACTIONS(3),
    [anon_sym_true] = ACTIONS(5),
    [anon_sym_false] = ACTIONS(5),
    [sym_varargs] = ACTIONS(7),
    [aux_sym_number_token1] = ACTIONS(9),
    [anon_sym_LBRACE] = ACTIONS(11),
    [sym__identifier] = ACTIONS(13),
    [sym__start_preproc_name] = ACTIONS(15),
    [sym__start_preproc_expr] = ACTIONS(17),
  },
  [2] = {
    [sym__expression] = STATE(26),
    [sym_boolean_literal] = STATE(26),
    [sym_number] = STATE(26),
    [sym_table_constructor] = STATE(26),
    [sym_field_list] = STATE(34),
    [sym_field_expression] = STATE(14),
    [sym__field_sugar_pair] = STATE(25),
    [sym__field_pair] = STATE(28),
    [sym_identifier] = STATE(22),
    [sym__preprocess_name] = STATE(10),
    [sym_preprocess_expr] = STATE(26),
    [sym_nil_literal] = ACTIONS(19),
    [sym_nilptr_literal] = ACTIONS(19),
    [anon_sym_true] = ACTIONS(5),
    [anon_sym_false] = ACTIONS(5),
    [sym_varargs] = ACTIONS(21),
    [aux_sym_number_token1] = ACTIONS(23),
    [anon_sym_LBRACE] = ACTIONS(11),
    [anon_sym_RBRACE] = ACTIONS(25),
    [anon_sym_EQ] = ACTIONS(27),
    [anon_sym_LBRACK] = ACTIONS(29),
    [sym__identifier] = ACTIONS(13),
    [sym__start_preproc_name] = ACTIONS(15),
    [sym__start_preproc_expr] = ACTIONS(17),
  },
  [3] = {
    [sym__expression] = STATE(26),
    [sym_boolean_literal] = STATE(26),
    [sym_number] = STATE(26),
    [sym_table_constructor] = STATE(26),
    [sym_field_expression] = STATE(27),
    [sym__field_sugar_pair] = STATE(25),
    [sym__field_pair] = STATE(28),
    [sym_identifier] = STATE(22),
    [sym__preprocess_name] = STATE(10),
    [sym_preprocess_expr] = STATE(26),
    [sym_nil_literal] = ACTIONS(19),
    [sym_nilptr_literal] = ACTIONS(19),
    [anon_sym_true] = ACTIONS(5),
    [anon_sym_false] = ACTIONS(5),
    [sym_varargs] = ACTIONS(21),
    [aux_sym_number_token1] = ACTIONS(23),
    [anon_sym_LBRACE] = ACTIONS(11),
    [anon_sym_RBRACE] = ACTIONS(31),
    [anon_sym_EQ] = ACTIONS(27),
    [anon_sym_LBRACK] = ACTIONS(29),
    [sym__identifier] = ACTIONS(13),
    [sym__start_preproc_name] = ACTIONS(15),
    [sym__start_preproc_expr] = ACTIONS(17),
  },
  [4] = {
    [sym__expression] = STATE(26),
    [sym_boolean_literal] = STATE(26),
    [sym_number] = STATE(26),
    [sym_table_constructor] = STATE(26),
    [sym_field_expression] = STATE(27),
    [sym__field_sugar_pair] = STATE(25),
    [sym__field_pair] = STATE(28),
    [sym_identifier] = STATE(22),
    [sym__preprocess_name] = STATE(10),
    [sym_preprocess_expr] = STATE(26),
    [sym_nil_literal] = ACTIONS(19),
    [sym_nilptr_literal] = ACTIONS(19),
    [anon_sym_true] = ACTIONS(5),
    [anon_sym_false] = ACTIONS(5),
    [sym_varargs] = ACTIONS(21),
    [aux_sym_number_token1] = ACTIONS(23),
    [anon_sym_LBRACE] = ACTIONS(11),
    [anon_sym_RBRACE] = ACTIONS(33),
    [anon_sym_EQ] = ACTIONS(27),
    [anon_sym_LBRACK] = ACTIONS(29),
    [sym__identifier] = ACTIONS(13),
    [sym__start_preproc_name] = ACTIONS(15),
    [sym__start_preproc_expr] = ACTIONS(17),
  },
  [5] = {
    [sym__expression] = STATE(26),
    [sym_boolean_literal] = STATE(26),
    [sym_number] = STATE(26),
    [sym_table_constructor] = STATE(26),
    [sym_field_expression] = STATE(27),
    [sym__field_sugar_pair] = STATE(25),
    [sym__field_pair] = STATE(28),
    [sym_identifier] = STATE(22),
    [sym__preprocess_name] = STATE(10),
    [sym_preprocess_expr] = STATE(26),
    [sym_nil_literal] = ACTIONS(19),
    [sym_nilptr_literal] = ACTIONS(19),
    [anon_sym_true] = ACTIONS(5),
    [anon_sym_false] = ACTIONS(5),
    [sym_varargs] = ACTIONS(21),
    [aux_sym_number_token1] = ACTIONS(23),
    [anon_sym_LBRACE] = ACTIONS(11),
    [anon_sym_EQ] = ACTIONS(27),
    [anon_sym_LBRACK] = ACTIONS(29),
    [sym__identifier] = ACTIONS(13),
    [sym__start_preproc_name] = ACTIONS(15),
    [sym__start_preproc_expr] = ACTIONS(17),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 10,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(13), 1,
      sym__identifier,
    ACTIONS(15), 1,
      sym__start_preproc_name,
    ACTIONS(17), 1,
      sym__start_preproc_expr,
    ACTIONS(23), 1,
      aux_sym_number_token1,
    ACTIONS(37), 1,
      sym_varargs,
    STATE(10), 1,
      sym__preprocess_name,
    ACTIONS(5), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(35), 2,
      sym_nil_literal,
      sym_nilptr_literal,
    STATE(36), 6,
      sym__expression,
      sym_boolean_literal,
      sym_number,
      sym_table_constructor,
      sym_identifier,
      sym_preprocess_expr,
  [38] = 10,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(13), 1,
      sym__identifier,
    ACTIONS(15), 1,
      sym__start_preproc_name,
    ACTIONS(17), 1,
      sym__start_preproc_expr,
    ACTIONS(23), 1,
      aux_sym_number_token1,
    ACTIONS(41), 1,
      sym_varargs,
    STATE(10), 1,
      sym__preprocess_name,
    ACTIONS(5), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(39), 2,
      sym_nil_literal,
      sym_nilptr_literal,
    STATE(23), 6,
      sym__expression,
      sym_boolean_literal,
      sym_number,
      sym_table_constructor,
      sym_identifier,
      sym_preprocess_expr,
  [76] = 10,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(13), 1,
      sym__identifier,
    ACTIONS(15), 1,
      sym__start_preproc_name,
    ACTIONS(17), 1,
      sym__start_preproc_expr,
    ACTIONS(23), 1,
      aux_sym_number_token1,
    ACTIONS(45), 1,
      sym_varargs,
    STATE(10), 1,
      sym__preprocess_name,
    ACTIONS(5), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(43), 2,
      sym_nil_literal,
      sym_nilptr_literal,
    STATE(29), 6,
      sym__expression,
      sym_boolean_literal,
      sym_number,
      sym_table_constructor,
      sym_identifier,
      sym_preprocess_expr,
  [114] = 2,
    ACTIONS(47), 5,
      sym_nil_literal,
      sym_nilptr_literal,
      anon_sym_true,
      anon_sym_false,
      sym__identifier,
    ACTIONS(49), 8,
      sym__start_preproc_name,
      sym__start_preproc_expr,
      sym_varargs,
      aux_sym_number_token1,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_EQ,
      anon_sym_LBRACK,
  [132] = 1,
    ACTIONS(51), 6,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_EQ,
      anon_sym_RBRACK,
  [141] = 1,
    ACTIONS(53), 6,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_EQ,
      anon_sym_RBRACK,
  [150] = 1,
    ACTIONS(55), 5,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACK,
  [158] = 1,
    ACTIONS(57), 5,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACK,
  [166] = 4,
    ACTIONS(59), 1,
      anon_sym_RBRACE,
    STATE(4), 1,
      sym_field_separator,
    STATE(19), 1,
      aux_sym_field_list_repeat1,
    ACTIONS(61), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
  [180] = 1,
    ACTIONS(63), 5,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACK,
  [188] = 1,
    ACTIONS(65), 5,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACK,
  [196] = 1,
    ACTIONS(67), 5,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACK,
  [204] = 4,
    ACTIONS(69), 1,
      anon_sym_RBRACE,
    STATE(5), 1,
      sym_field_separator,
    STATE(18), 1,
      aux_sym_field_list_repeat1,
    ACTIONS(71), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
  [218] = 4,
    ACTIONS(33), 1,
      anon_sym_RBRACE,
    STATE(3), 1,
      sym_field_separator,
    STATE(18), 1,
      aux_sym_field_list_repeat1,
    ACTIONS(61), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
  [232] = 2,
    ACTIONS(76), 1,
      sym__identifier,
    ACTIONS(74), 4,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACK,
  [242] = 4,
    ACTIONS(15), 1,
      sym__start_preproc_name,
    ACTIONS(78), 1,
      sym__identifier,
    STATE(10), 1,
      sym__preprocess_name,
    STATE(24), 1,
      sym_identifier,
  [255] = 2,
    ACTIONS(82), 1,
      anon_sym_EQ,
    ACTIONS(80), 3,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_SEMI,
  [264] = 1,
    ACTIONS(84), 3,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_SEMI,
  [270] = 1,
    ACTIONS(86), 3,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_SEMI,
  [276] = 1,
    ACTIONS(88), 3,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_SEMI,
  [282] = 1,
    ACTIONS(90), 3,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_SEMI,
  [288] = 1,
    ACTIONS(69), 3,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_SEMI,
  [294] = 1,
    ACTIONS(92), 3,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_SEMI,
  [300] = 1,
    ACTIONS(94), 3,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_SEMI,
  [306] = 2,
    ACTIONS(74), 1,
      ts_builtin_sym_end,
    ACTIONS(76), 1,
      sym__identifier,
  [313] = 1,
    ACTIONS(96), 1,
      sym__content_preproc_inline,
  [317] = 1,
    ACTIONS(98), 1,
      sym__content_preproc_inline,
  [321] = 1,
    ACTIONS(100), 1,
      anon_sym_EQ,
  [325] = 1,
    ACTIONS(102), 1,
      anon_sym_RBRACE,
  [329] = 1,
    ACTIONS(104), 1,
      ts_builtin_sym_end,
  [333] = 1,
    ACTIONS(106), 1,
      anon_sym_RBRACK,
  [337] = 1,
    ACTIONS(108), 1,
      ts_builtin_sym_end,
  [341] = 1,
    ACTIONS(110), 1,
      sym__end_preproc_name,
  [345] = 1,
    ACTIONS(112), 1,
      sym__end_preproc_expr,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(6)] = 0,
  [SMALL_STATE(7)] = 38,
  [SMALL_STATE(8)] = 76,
  [SMALL_STATE(9)] = 114,
  [SMALL_STATE(10)] = 132,
  [SMALL_STATE(11)] = 141,
  [SMALL_STATE(12)] = 150,
  [SMALL_STATE(13)] = 158,
  [SMALL_STATE(14)] = 166,
  [SMALL_STATE(15)] = 180,
  [SMALL_STATE(16)] = 188,
  [SMALL_STATE(17)] = 196,
  [SMALL_STATE(18)] = 204,
  [SMALL_STATE(19)] = 218,
  [SMALL_STATE(20)] = 232,
  [SMALL_STATE(21)] = 242,
  [SMALL_STATE(22)] = 255,
  [SMALL_STATE(23)] = 264,
  [SMALL_STATE(24)] = 270,
  [SMALL_STATE(25)] = 276,
  [SMALL_STATE(26)] = 282,
  [SMALL_STATE(27)] = 288,
  [SMALL_STATE(28)] = 294,
  [SMALL_STATE(29)] = 300,
  [SMALL_STATE(30)] = 306,
  [SMALL_STATE(31)] = 313,
  [SMALL_STATE(32)] = 317,
  [SMALL_STATE(33)] = 321,
  [SMALL_STATE(34)] = 325,
  [SMALL_STATE(35)] = 329,
  [SMALL_STATE(36)] = 333,
  [SMALL_STATE(37)] = 337,
  [SMALL_STATE(38)] = 341,
  [SMALL_STATE(39)] = 345,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_field_list, 3, 0, 0),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_field_list, 2, 0, 0),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [43] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [47] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_field_separator, 1, 0, 0),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_field_separator, 1, 0, 0),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier, 1, 0, 0),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__preprocess_name, 3, 0, 0),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number, 2, 0, 0),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table_constructor, 2, 0, 0),
  [59] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_field_list, 1, 0, 0),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean_literal, 1, 0, 0),
  [65] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table_constructor, 3, 0, 0),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_preprocess_expr, 3, 0, 0),
  [69] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_field_list_repeat1, 2, 0, 0),
  [71] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_field_list_repeat1, 2, 0, 0), SHIFT_REPEAT(9),
  [74] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number, 1, 0, 0),
  [76] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [78] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [80] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expression, 1, 0, 0),
  [82] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [84] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__field_pair, 3, 0, 4),
  [86] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__field_sugar_pair, 2, 0, 0),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_field_expression, 1, 0, 2),
  [90] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_field_expression, 1, 0, 1),
  [92] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_field_expression, 1, 0, 3),
  [94] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__field_pair, 5, 0, 5),
  [96] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [98] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [100] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [102] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chunk, 1, 0, 0),
  [106] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [108] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [110] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [112] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
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

static const bool ts_external_scanner_states[7][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__start_preproc_name] = true,
    [ts_external_token__start_preproc_expr] = true,
    [ts_external_token__content_preproc_inline] = true,
    [ts_external_token__end_preproc_name] = true,
    [ts_external_token__end_preproc_expr] = true,
  },
  [2] = {
    [ts_external_token__start_preproc_name] = true,
    [ts_external_token__start_preproc_expr] = true,
  },
  [3] = {
    [ts_external_token__start_preproc_name] = true,
  },
  [4] = {
    [ts_external_token__content_preproc_inline] = true,
  },
  [5] = {
    [ts_external_token__end_preproc_name] = true,
  },
  [6] = {
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
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
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
