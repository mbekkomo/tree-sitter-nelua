/**
 * @file A tree-sitter grammar for Nelua
 * @author Komo <afiqquraisyzulkarnain@gmail.com>
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

const PREC = {
  OR: 1,  /* or */
  AND: 2, /* and */
  COMP: 3,  /* < > <= >= ~= == */
  BITOR: 4, /* | */
  BITXOR: 5, /* ~ */
  BITAND: 6, /* & */
  BITSHIFT: 7, /* << >>> << */
  CONCAT: 8, /* .. */
  ARITH: 9,  /* + - */
  FACTOR: 10, /* * /// // / %%% % */
  UNARY: 11, /* not - # ~ & */
  POW: 12,   /* ^ */

  TGENERIC: 1,
  TVARIANTS: 2,
  TUNARY: 3,
};

module.exports = grammar({
  name: "nelua",

  extras: $ => [
    /[\s\r]+/,
    $.comment,
  ],

  externals: $ => [
    $._start_preproc_name,
    $._end_preproc_name,
    $._start_preproc_expr,
    $._end_preproc_expr,
    $._content_preproc_inline,
    $._block_string_opening,
    $._block_string_ending,
    $._block_string_content,
    $._block_comment_opening,
    $._block_comment_ending,
    $._block_comment_content,
    $._block_preproc_opening,
    $._block_preproc_ending,
    $._block_preproc_content,
  ],

  conflicts: $ => [
    [$._expression, $._variable],
    [$._expression, $._variable, $._type],
  ],


  rules: {
    chunk: $ => $._expression,

    comment: $ => either(
      ["--", /[^\n\r]*/],
      [$._block_comment_opening, $._block_comment_content, $._block_comment_ending],
    ),

    _expression: $ => choice(
      $._parentheses_exp,
      $.prefix_exp,
      $.number,
      $.string,
      $.identifier,
      $.nil_literal,
      $.nilptr_literal,
      $.boolean_literal,
      $.varargs,
      $.table_constructor,
      $.type,
      $.preprocess_expr,
      $.binary_operation,
      $.unary_operation,
    ),

    preprocessor: $ => either(
      ["##", alias(/[^\n\r]+/, $.lua_statement)],
      [$._block_preproc_opening, alias($._block_preproc_content, $.lua_statement), $._block_preproc_ending],
    ),

    prefix_exp: $ => choice(
      $._variable,
    ),

    _variable: $ => either(
      [$.identifier],
      [$.prefix_exp, ".", $.identifier],
      [$.prefix_exp, "[", $._expression, "]"]
    ),

    _parentheses_exp: $ => seq("(", $._expression, ")"),

    nil_literal: _ => "nil",
    nilptr_literal: _ => "nilptr",

    boolean_literal: _ => choice("true", "false"),

    varargs: _ => "...",

    number: $ => {
      const decimal_digits = /[0-9]+/;
      const hex_digits = /[0-9a-fA-F]+/;
      const bin_digits = /[01]+/;

      const exp_digits = seq(any_of("-", "+"), decimal_digits);

      const decimal_prefix = either(
        [decimal_digits, may_seq(".", optional(decimal_digits))],
        [".", decimal_digits],
      );

      const hex_prefix = either(
        [hex_digits, may_seq(".", optional(hex_digits))],
        [".", hex_digits],
      );

      const bin_prefix = either(
        [bin_digits, may_seq(".", optional(bin_digits))],
        [".", bin_digits],
      );

      const decimal_number = seq(
        decimal_prefix,
        may_seq(
          choice("e", "E"),
          exp_digits,
        ),
      );

      const hex_number = seq(
        choice("0x", "0X"),
        hex_prefix,
        may_seq(
          choice("p", "P"),
          exp_digits,
        ),
      );

      const bin_number = seq(
        choice("0b", "0B"),
        bin_prefix,
        may_seq(
          choice("p", "P"),
          exp_digits,
        ),
      );

      return seq(
        field("number", token(choice(decimal_number, hex_number, bin_number))),
        field("suffix", optional($._identifier)),
      );
    },

    string: $ => choice($._single_quote_string, $._double_quote_string, $._block_string),

    _block_string: $ => seq_field({
      opening: alias($._block_string_opening, $.string_opening),
      content: alias($._block_string_content, $.string_content),
      ending: alias($._block_string_ending, $.string_ending),
    }),

    _single_quote_string: $ => seq_field({
      opening: alias("'", $.string_opening),
      content: optional(alias($._single_quote_string_content, $.string_content)),
      ending: alias("'", $.string_ending),
    }),

    _double_quote_string: $ => seq_field({
      opening: alias("\"", $.string_opening),
      content: optional(alias($._double_quote_string_content, $.string_content)),
      ending: alias("\"", $.string_ending),
    }),

    _single_quote_string_content: $ => repeat1(choice(
      token.immediate(prec(1, /[^\n'\\]+/)),
      $.escape_sequence
    )),

    _double_quote_string_content: $ => repeat1(choice(
      token.immediate(prec(1, /[^\n"\\]+/)),
      $.escape_sequence
    )),

    escape_sequence: _ => token.immediate(
      seq('\\', choice(
        /[\nabfnrtv\\"']/,
        /z\s*/,
        /[0-9]{1,3}/,
        /x[0-9a-fA-F]{2}/,
        /u\{[0-9a-fA-F]+\}/,
      ))
    ),

    table_constructor: $ => seq("{", optional($._field_list), "}"),

    _field_list: $ => seq(
      $.table_field,
      any_amount_of($._field_separator, $.table_field),
      optional($._field_separator)
    ),
    table_field: $ => choice(
      $._field_pair,
      $._field_sugar_pair,
      field("value", $._expression),
    ),
    _field_sugar_pair: $ => seq("=", field("key", $.identifier)),
    _field_pair: $ => seq(
      either(
        [field("key", $.identifier)],
        ["[", field("key", $._expression), "]"],
      ),
      "=",
      field("value", $._expression),
    ),
    _field_separator: _ => choice(",", ";"),

    type: $ => prec.left(seq("@", $._type)),

    binary_operation: $ => choice(
      ...[
        ["or", PREC.OR],
        ["and", PREC.AND],
        ["<", PREC.COMP],
        [">", PREC.COMP],
        ["<=", PREC.COMP],
        [">=", PREC.COMP],
        ["~=", PREC.COMP],
        ["==", PREC.COMP],
        ["|", PREC.BITOR],
        ["~", PREC.BITXOR],
        ["&", PREC.BITAND],
        ["<<", PREC.BITSHIFT],
        [">>>", PREC.BITSHIFT],
        [">>", PREC.BITSHIFT],
        ["+", PREC.ARITH],
        ["-", PREC.ARITH],
        ["*", PREC.FACTOR],
        ["///", PREC.FACTOR],
        ["//", PREC.FACTOR],
        ["/", PREC.FACTOR],
        ["%%%", PREC.FACTOR],
        ["%", PREC.FACTOR],
      ].map(([operator, precedence]) =>
        prec.left(precedence, seq($._expression, operator, $._expression))),
      ...[
        ["..", PREC.CONCAT],
        ["^", PREC.POW]
      ].map(([operator, precedence]) =>
        prec.right(precedence, seq($._expression, operator, $._expression)))
    ),

    unary_operation: $ => prec.left(PREC.UNARY, seq(
      choice("not", "-", "#", "~", "&", "$"),
      $._expression,
    )),

    identifier: $ => $._identifier,
    _identifier: $ => choice($._name, $._preprocess_name),
    _name: _ => /[_a-zA-Z][_a-zA-Z0-9]*/,
    _preprocess_name: $ => seq(
      $._start_preproc_name,
      alias($._content_preproc_inline, $.lua_expression),
      $._end_preproc_name,
    ),

    preprocess_expr: $ => seq(
      $._start_preproc_expr,
      alias(
        $._content_preproc_inline,
        $.lua_expression
      ),
      $._end_preproc_expr,
    ),

    _id_suffixed: $ => prec(1, seq($.identifier, atleast_amount_of(".", $.identifier))),

    _type: $ => choice(
      field("type", $.identifier),
      field("type", $._id_suffixed),
      $.type_unary,
      $.type_variants,
      $.type_generic,
      $.type_record,
      $.type_union,
      $.type_enum,
      $.type_array,
      $.type_pointer,
      $.type_variant,
    ),

    type_unary: $ => prec.left(PREC.TUNARY, seq(
      field("suffix", choice($.type_unary_pointer, $.type_unary_optional, $.type_unary_array)),
      field("type", alias($._type, $.type)),
    )),

    type_variants: $ => prec.left(PREC.TVARIANTS, seq($._type, atleast_amount_of("|", $._type))),

    type_generic: $ => prec.left(PREC.TGENERIC, seq(
      field("type", $._type),
      either(
        ["(", field("args", optional($.type_args)), ")"],
        [$.table_constructor],
      ),
    )),

    type_unary_pointer: _ => "*",
    type_unary_optional: _ => "?",
    type_unary_array: $ => seq("[", optional($._expression), "]"),

    type_args: $ => prec(-1, choice(
      seq($._type_arg, any_amount_of(",", $._type_arg)),
      $.table_constructor,
    )),
    _type_arg: $ => choice($._type, $._expression),

    type_record: $ => seq(
      "record",
      "{",
      alias($._type_field, $.type_record_field),
      any_amount_of(
        $._field_separator,
        alias($._type_field, $.type_record_field),
      ),
      optional($._field_separator),
      "}"
    ),

    type_union: $ => seq(
      "union",
      "{",
      field("field", alias($._type_field, $.type_union_field)),
      any_amount_of(
        $._field_separator,
        field("field", alias($._type_field, $.type_union_field)),
      ),
      optional($._field_separator),
      "}",
    ),

    type_enum: $ => seq(
      "enum",
      may_seq(
        "(",
        field("enumtype", alias($._type, $.type)),
        ")",
      ),
      "{",
      field("field", alias($._enum_required_field, $.type_enum_field)),
      any_amount_of(
        $._field_separator,
        field("field", alias($._enum_field, $.type_enum_field)),
      ),
      optional($._field_separator),
      "}"
    ),

    type_array: $ => seq(
      "array",
      "(",
      field("arraytype", alias($._type, $.type)),
      may_seq(
        ",",
        alias("length", $._expression),
      ),
      ")"
    ),

    type_pointer: $ => seq(
      "pointer",
      "(",
      field("pointertype", alias($._type, $.type)),
      ")"
    ),

    type_variant: $ => seq(
      "variant",
      "(",
      field("arg", $._variant_arg),
      any_amount_of(
        ",",
        field("arg", $._variant_arg),
      ),
      ")"
    ),

    _type_field: $ => seq($.identifier, ":", $._type),

    _enum_required_field: $ => seq($.identifier, "=", $._expression),
    _enum_field: $ => seq($.identifier, may_seq("=", $._expression)),

    _variant_arg: $ => prec(1, either(
      [alias($._type, $.type)],
      [$._parentheses_exp],
      [$._expression],
    )),
  },
});

function any_of(...args) {
  return optional(choice(...args));
}

function atleast_amount_of(...args) {
  return repeat1(seq(...args));
}

function any_amount_of(...args) {
  return repeat(seq(...args));
}

function may_seq(...args) {
  return optional(seq(...args));
}

function either(...args) {
  let choices = [];
  args.forEach(arg => choices.push(seq(...arg)));
  return choice(...choices);
}

function seq_field(obj) {
  return seq(...Object.keys(obj).map(k => field(k, obj[k])));
}
