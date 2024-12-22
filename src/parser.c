#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 41
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 31
#define ALIAS_COUNT 0
#define TOKEN_COUNT 26
#define EXTERNAL_TOKEN_COUNT 5
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 8
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  sym_nil_literal = 1,
  sym_nilptr_literal = 2,
  anon_sym_true = 3,
  anon_sym_false = 4,
  sym_varargs = 5,
  aux_sym_number_token1 = 6,
  anon_sym_DOT = 7,
  anon_sym_e = 8,
  anon_sym_E = 9,
  anon_sym_DASH = 10,
  anon_sym_PLUS = 11,
  anon_sym_0x = 12,
  anon_sym_0X = 13,
  aux_sym_number_token2 = 14,
  anon_sym_p = 15,
  anon_sym_P = 16,
  anon_sym_0b = 17,
  anon_sym_0B = 18,
  aux_sym_number_token3 = 19,
  sym__identifier = 20,
  sym__start_preproc_name = 21,
  sym__start_preproc_expr = 22,
  sym__content_preproc_inline = 23,
  sym__end_preproc_name = 24,
  sym__end_preproc_expr = 25,
  sym_chunk = 26,
  sym__expressions = 27,
  sym_boolean_literal = 28,
  sym_number = 29,
  sym_identifier = 30,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_nil_literal] = "nil_literal",
  [sym_nilptr_literal] = "nilptr_literal",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [sym_varargs] = "varargs",
  [aux_sym_number_token1] = "number_token1",
  [anon_sym_DOT] = ".",
  [anon_sym_e] = "e",
  [anon_sym_E] = "E",
  [anon_sym_DASH] = "-",
  [anon_sym_PLUS] = "+",
  [anon_sym_0x] = "0x",
  [anon_sym_0X] = "0X",
  [aux_sym_number_token2] = "number_token2",
  [anon_sym_p] = "p",
  [anon_sym_P] = "P",
  [anon_sym_0b] = "0b",
  [anon_sym_0B] = "0B",
  [aux_sym_number_token3] = "number_token3",
  [sym__identifier] = "_identifier",
  [sym__start_preproc_name] = "_start_preproc_name",
  [sym__start_preproc_expr] = "_start_preproc_expr",
  [sym__content_preproc_inline] = "_content_preproc_inline",
  [sym__end_preproc_name] = "_end_preproc_name",
  [sym__end_preproc_expr] = "_end_preproc_expr",
  [sym_chunk] = "chunk",
  [sym__expressions] = "_expressions",
  [sym_boolean_literal] = "boolean_literal",
  [sym_number] = "number",
  [sym_identifier] = "identifier",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_nil_literal] = sym_nil_literal,
  [sym_nilptr_literal] = sym_nilptr_literal,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [sym_varargs] = sym_varargs,
  [aux_sym_number_token1] = aux_sym_number_token1,
  [anon_sym_DOT] = anon_sym_DOT,
  [anon_sym_e] = anon_sym_e,
  [anon_sym_E] = anon_sym_E,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_0x] = anon_sym_0x,
  [anon_sym_0X] = anon_sym_0X,
  [aux_sym_number_token2] = aux_sym_number_token2,
  [anon_sym_p] = anon_sym_p,
  [anon_sym_P] = anon_sym_P,
  [anon_sym_0b] = anon_sym_0b,
  [anon_sym_0B] = anon_sym_0B,
  [aux_sym_number_token3] = aux_sym_number_token3,
  [sym__identifier] = sym__identifier,
  [sym__start_preproc_name] = sym__start_preproc_name,
  [sym__start_preproc_expr] = sym__start_preproc_expr,
  [sym__content_preproc_inline] = sym__content_preproc_inline,
  [sym__end_preproc_name] = sym__end_preproc_name,
  [sym__end_preproc_expr] = sym__end_preproc_expr,
  [sym_chunk] = sym_chunk,
  [sym__expressions] = sym__expressions,
  [sym_boolean_literal] = sym_boolean_literal,
  [sym_number] = sym_number,
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
  [aux_sym_number_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_e] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_E] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_0x] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_0X] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_number_token2] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_p] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_P] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_0b] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_0B] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_number_token3] = {
    .visible = false,
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
  [sym_number] = {
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
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(8);
      ADVANCE_MAP(
        '+', 22,
        '-', 21,
        '.', 18,
        'E', 20,
        'P', 28,
        'e', 19,
        'f', 32,
        'n', 35,
        'p', 27,
        't', 38,
        '0', 15,
        '1', 15,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('2' <= lookahead && lookahead <= '9')) ADVANCE(16);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(43);
      END_STATE();
    case 1:
      if (lookahead == '.') ADVANCE(18);
      if (lookahead == '0') ADVANCE(14);
      if (lookahead == 'f') ADVANCE(32);
      if (lookahead == 'n') ADVANCE(35);
      if (lookahead == 't') ADVANCE(38);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(16);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(43);
      END_STATE();
    case 2:
      if (lookahead == '.') ADVANCE(13);
      END_STATE();
    case 3:
      if (lookahead == '.') ADVANCE(17);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(25);
      END_STATE();
    case 4:
      if (eof) ADVANCE(8);
      if (lookahead == '+') ADVANCE(22);
      if (lookahead == '-') ADVANCE(21);
      if (lookahead == '.') ADVANCE(17);
      if (lookahead == 'E') ADVANCE(20);
      if (lookahead == 'e') ADVANCE(19);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(4);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(16);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(43);
      END_STATE();
    case 5:
      if (eof) ADVANCE(8);
      if (lookahead == '.') ADVANCE(17);
      if (lookahead == 'P') ADVANCE(28);
      if (lookahead == 'p') ADVANCE(27);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(31);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(5);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(43);
      END_STATE();
    case 6:
      if (eof) ADVANCE(8);
      if (lookahead == 'P') ADVANCE(28);
      if (lookahead == 'p') ADVANCE(27);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(6);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(25);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(26);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(43);
      END_STATE();
    case 7:
      if (eof) ADVANCE(8);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(43);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(sym_nil_literal);
      if (lookahead == 'p') ADVANCE(41);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(43);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(sym_nilptr_literal);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(43);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(anon_sym_true);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(43);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(anon_sym_false);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(43);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(sym_varargs);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == 'B') ADVANCE(30);
      if (lookahead == 'X') ADVANCE(24);
      if (lookahead == 'b') ADVANCE(29);
      if (lookahead == 'x') ADVANCE(23);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(16);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(15);
      if (('2' <= lookahead && lookahead <= '9')) ADVANCE(16);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(16);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_DOT);
      if (lookahead == '.') ADVANCE(2);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_e);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(43);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_E);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(43);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_0x);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_0X);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(aux_sym_number_token2);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(25);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(aux_sym_number_token2);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(26);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(43);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_p);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(43);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_P);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(43);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_0b);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_0B);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(aux_sym_number_token3);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(31);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym__identifier);
      if (lookahead == 'a') ADVANCE(36);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(43);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym__identifier);
      if (lookahead == 'e') ADVANCE(11);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(43);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym__identifier);
      if (lookahead == 'e') ADVANCE(12);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(43);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym__identifier);
      if (lookahead == 'i') ADVANCE(37);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(43);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym__identifier);
      if (lookahead == 'l') ADVANCE(40);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(43);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym__identifier);
      if (lookahead == 'l') ADVANCE(9);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(43);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym__identifier);
      if (lookahead == 'r') ADVANCE(42);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(43);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym__identifier);
      if (lookahead == 'r') ADVANCE(10);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(43);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym__identifier);
      if (lookahead == 's') ADVANCE(34);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(43);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym__identifier);
      if (lookahead == 't') ADVANCE(39);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(43);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym__identifier);
      if (lookahead == 'u') ADVANCE(33);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(43);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym__identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(43);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 1},
  [2] = {.lex_state = 4},
  [3] = {.lex_state = 4},
  [4] = {.lex_state = 5},
  [5] = {.lex_state = 5},
  [6] = {.lex_state = 5},
  [7] = {.lex_state = 6},
  [8] = {.lex_state = 4},
  [9] = {.lex_state = 4},
  [10] = {.lex_state = 5},
  [11] = {.lex_state = 5},
  [12] = {.lex_state = 4},
  [13] = {.lex_state = 4},
  [14] = {.lex_state = 4},
  [15] = {.lex_state = 4},
  [16] = {.lex_state = 3},
  [17] = {.lex_state = 5},
  [18] = {.lex_state = 7},
  [19] = {.lex_state = 7},
  [20] = {.lex_state = 7},
  [21] = {.lex_state = 7},
  [22] = {.lex_state = 7},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 3},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 5},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 4},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 4},
  [32] = {.lex_state = 4},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 4},
  [37] = {.lex_state = 4},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 0},
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
    [anon_sym_DOT] = ACTIONS(1),
    [anon_sym_e] = ACTIONS(1),
    [anon_sym_E] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_p] = ACTIONS(1),
    [anon_sym_P] = ACTIONS(1),
    [aux_sym_number_token3] = ACTIONS(1),
    [sym__identifier] = ACTIONS(1),
    [sym__start_preproc_name] = ACTIONS(1),
    [sym__start_preproc_expr] = ACTIONS(1),
    [sym__content_preproc_inline] = ACTIONS(1),
    [sym__end_preproc_name] = ACTIONS(1),
    [sym__end_preproc_expr] = ACTIONS(1),
  },
  [1] = {
    [sym_chunk] = STATE(25),
    [sym__expressions] = STATE(28),
    [sym_boolean_literal] = STATE(28),
    [sym_number] = STATE(28),
    [sym_identifier] = STATE(28),
    [sym_nil_literal] = ACTIONS(3),
    [sym_nilptr_literal] = ACTIONS(3),
    [anon_sym_true] = ACTIONS(5),
    [anon_sym_false] = ACTIONS(5),
    [sym_varargs] = ACTIONS(7),
    [aux_sym_number_token1] = ACTIONS(9),
    [anon_sym_DOT] = ACTIONS(11),
    [anon_sym_0x] = ACTIONS(13),
    [anon_sym_0X] = ACTIONS(13),
    [anon_sym_0b] = ACTIONS(15),
    [anon_sym_0B] = ACTIONS(15),
    [sym__identifier] = ACTIONS(17),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 4,
    ACTIONS(19), 1,
      ts_builtin_sym_end,
    ACTIONS(21), 1,
      anon_sym_DOT,
    ACTIONS(25), 1,
      sym__identifier,
    ACTIONS(23), 2,
      anon_sym_e,
      anon_sym_E,
  [14] = 4,
    ACTIONS(27), 1,
      ts_builtin_sym_end,
    ACTIONS(29), 1,
      aux_sym_number_token1,
    ACTIONS(33), 1,
      sym__identifier,
    ACTIONS(31), 2,
      anon_sym_e,
      anon_sym_E,
  [28] = 4,
    ACTIONS(27), 1,
      ts_builtin_sym_end,
    ACTIONS(33), 1,
      sym__identifier,
    ACTIONS(35), 1,
      anon_sym_DOT,
    ACTIONS(31), 2,
      anon_sym_p,
      anon_sym_P,
  [42] = 4,
    ACTIONS(27), 1,
      ts_builtin_sym_end,
    ACTIONS(33), 1,
      sym__identifier,
    ACTIONS(37), 1,
      anon_sym_DOT,
    ACTIONS(31), 2,
      anon_sym_p,
      anon_sym_P,
  [56] = 4,
    ACTIONS(39), 1,
      ts_builtin_sym_end,
    ACTIONS(43), 1,
      aux_sym_number_token3,
    ACTIONS(45), 1,
      sym__identifier,
    ACTIONS(41), 2,
      anon_sym_p,
      anon_sym_P,
  [70] = 4,
    ACTIONS(39), 1,
      ts_builtin_sym_end,
    ACTIONS(45), 1,
      sym__identifier,
    ACTIONS(47), 1,
      aux_sym_number_token2,
    ACTIONS(41), 2,
      anon_sym_p,
      anon_sym_P,
  [84] = 3,
    ACTIONS(27), 1,
      ts_builtin_sym_end,
    ACTIONS(33), 1,
      sym__identifier,
    ACTIONS(31), 2,
      anon_sym_e,
      anon_sym_E,
  [95] = 3,
    ACTIONS(39), 1,
      ts_builtin_sym_end,
    ACTIONS(45), 1,
      sym__identifier,
    ACTIONS(41), 2,
      anon_sym_e,
      anon_sym_E,
  [106] = 3,
    ACTIONS(39), 1,
      ts_builtin_sym_end,
    ACTIONS(45), 1,
      sym__identifier,
    ACTIONS(41), 2,
      anon_sym_p,
      anon_sym_P,
  [117] = 3,
    ACTIONS(49), 1,
      ts_builtin_sym_end,
    ACTIONS(53), 1,
      sym__identifier,
    ACTIONS(51), 2,
      anon_sym_p,
      anon_sym_P,
  [128] = 2,
    ACTIONS(55), 1,
      aux_sym_number_token1,
    ACTIONS(57), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
  [136] = 2,
    ACTIONS(59), 1,
      aux_sym_number_token1,
    ACTIONS(61), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
  [144] = 2,
    ACTIONS(63), 1,
      aux_sym_number_token1,
    ACTIONS(65), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
  [152] = 2,
    ACTIONS(67), 1,
      aux_sym_number_token1,
    ACTIONS(69), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
  [160] = 2,
    ACTIONS(71), 1,
      anon_sym_DOT,
    ACTIONS(73), 1,
      aux_sym_number_token2,
  [167] = 2,
    ACTIONS(75), 1,
      anon_sym_DOT,
    ACTIONS(77), 1,
      aux_sym_number_token3,
  [174] = 2,
    ACTIONS(49), 1,
      ts_builtin_sym_end,
    ACTIONS(79), 1,
      sym__identifier,
  [181] = 2,
    ACTIONS(81), 1,
      ts_builtin_sym_end,
    ACTIONS(83), 1,
      sym__identifier,
  [188] = 2,
    ACTIONS(39), 1,
      ts_builtin_sym_end,
    ACTIONS(85), 1,
      sym__identifier,
  [195] = 2,
    ACTIONS(87), 1,
      ts_builtin_sym_end,
    ACTIONS(89), 1,
      sym__identifier,
  [202] = 2,
    ACTIONS(91), 1,
      ts_builtin_sym_end,
    ACTIONS(93), 1,
      sym__identifier,
  [209] = 1,
    ACTIONS(87), 1,
      ts_builtin_sym_end,
  [213] = 1,
    ACTIONS(95), 1,
      aux_sym_number_token2,
  [217] = 1,
    ACTIONS(97), 1,
      ts_builtin_sym_end,
  [221] = 1,
    ACTIONS(95), 1,
      aux_sym_number_token3,
  [225] = 1,
    ACTIONS(49), 1,
      ts_builtin_sym_end,
  [229] = 1,
    ACTIONS(99), 1,
      ts_builtin_sym_end,
  [233] = 1,
    ACTIONS(67), 1,
      aux_sym_number_token1,
  [237] = 1,
    ACTIONS(101), 1,
      ts_builtin_sym_end,
  [241] = 1,
    ACTIONS(103), 1,
      aux_sym_number_token1,
  [245] = 1,
    ACTIONS(63), 1,
      aux_sym_number_token1,
  [249] = 1,
    ACTIONS(81), 1,
      ts_builtin_sym_end,
  [253] = 1,
    ACTIONS(39), 1,
      ts_builtin_sym_end,
  [257] = 1,
    ACTIONS(27), 1,
      ts_builtin_sym_end,
  [261] = 1,
    ACTIONS(59), 1,
      aux_sym_number_token1,
  [265] = 1,
    ACTIONS(105), 1,
      aux_sym_number_token1,
  [269] = 1,
    ACTIONS(91), 1,
      ts_builtin_sym_end,
  [273] = 1,
    ACTIONS(107), 1,
      ts_builtin_sym_end,
  [277] = 1,
    ACTIONS(109), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 14,
  [SMALL_STATE(4)] = 28,
  [SMALL_STATE(5)] = 42,
  [SMALL_STATE(6)] = 56,
  [SMALL_STATE(7)] = 70,
  [SMALL_STATE(8)] = 84,
  [SMALL_STATE(9)] = 95,
  [SMALL_STATE(10)] = 106,
  [SMALL_STATE(11)] = 117,
  [SMALL_STATE(12)] = 128,
  [SMALL_STATE(13)] = 136,
  [SMALL_STATE(14)] = 144,
  [SMALL_STATE(15)] = 152,
  [SMALL_STATE(16)] = 160,
  [SMALL_STATE(17)] = 167,
  [SMALL_STATE(18)] = 174,
  [SMALL_STATE(19)] = 181,
  [SMALL_STATE(20)] = 188,
  [SMALL_STATE(21)] = 195,
  [SMALL_STATE(22)] = 202,
  [SMALL_STATE(23)] = 209,
  [SMALL_STATE(24)] = 213,
  [SMALL_STATE(25)] = 217,
  [SMALL_STATE(26)] = 221,
  [SMALL_STATE(27)] = 225,
  [SMALL_STATE(28)] = 229,
  [SMALL_STATE(29)] = 233,
  [SMALL_STATE(30)] = 237,
  [SMALL_STATE(31)] = 241,
  [SMALL_STATE(32)] = 245,
  [SMALL_STATE(33)] = 249,
  [SMALL_STATE(34)] = 253,
  [SMALL_STATE(35)] = 257,
  [SMALL_STATE(36)] = 261,
  [SMALL_STATE(37)] = 265,
  [SMALL_STATE(38)] = 269,
  [SMALL_STATE(39)] = 273,
  [SMALL_STATE(40)] = 277,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(39),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number, 1, 0, 0),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number, 2, 0, 0),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(34),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number, 3, 0, 0),
  [41] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [45] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [47] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number, 4, 0, 0),
  [51] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [53] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [55] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [69] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [73] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [75] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [77] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [79] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number, 5, 0, 0),
  [83] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [85] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number, 6, 0, 0),
  [89] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number, 7, 0, 0),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [95] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [97] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chunk, 1, 0, 0),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean_literal, 1, 0, 0),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [107] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier, 1, 0, 0),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number, 8, 0, 0),
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
