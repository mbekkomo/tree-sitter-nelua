/**
 * @file A tree-sitter grammar for Nelua
 * @author Komo <afiqquraisyzulkarnain@gmail.com>
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

const PREC = {
  LIST: -1,
  DEFAULT: 1,

  OR: 2,  /* or */
  AND: 3, /* and */
  COMP: 4,  /* < > <= >= ~= == */
  BITOR: 6, /* | */
  BITXOR: 7, /* ~ */
  BITAND: 8, /* & */
  BITSHIFT: 9, /* << >>> << */
  CONCAT: 10, /* .. */
  ARITH: 11,  /* + - */
  FACTOR: 12, /* * /// // / %%% % */
  UNARY: 13, /* not - # ~ & */
  POW: 14,   /* ^ */

  TGENERIC: 2,
  TVARIANTS: 3,
  TUNARY: 4,
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
    $.string_opening,
    $.string_ending,
    $.string_content,
    $._block_comment_opening,
    $._block_comment_ending,
    $._block_comment_content,
  ],

  conflicts: $ => [
    [$._expression, $._variable],
    [$._expression, $._variable, $._type],
  ],

  inline: $ => [
    $.comment,
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

    string: $ => seq(
      field("opening", $.string_opening),
      field("content", $.string_content),
      field("ending", $.string_ending),
    ),

    table_constructor: $ => seq("{", optional($.field_list), "}"),

    field_list: $ => seq(
      $.field_expression,
      any_amount_of($._field_separator, $.field_expression),
      optional($._field_separator)
    ),
    field_expression: $ => choice(
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
        // $._content_preproc_inline,
        "aaa",
        $.lua_expression
      ),
      $._end_preproc_expr,
    ),

    // idsuffixed      <-- (id DotIndex+)~>rfoldright
    _id_suffixed: $ => prec(PREC.DEFAULT, seq($.identifier, atleast_amount_of(".", $.identifier))),

    _type: $ => choice(
      field("type", $.identifier),
      field("type", $._id_suffixed),
      $._type_unary,
      $._type_variants,
      $._type_generic,
    ),
    _type_unary: $ => prec.left(PREC.TUNARY, seq(
      field("suffix", choice($.type_pointer, $.type_optional, $.type_array)),
      field("type", $._type),
    )),
    _type_variants: $ => prec.left(PREC.TVARIANTS, seq($._type, atleast_amount_of("|", $._type))),
    _type_generic: $ => prec.left(PREC.TGENERIC, seq(
      field("type", $._type),
      either(
        ["(", field("args", optional($.type_args)), ")"],
        [$.table_constructor],
      ),
    )),
    type_pointer: _ => "*",
    type_optional: _ => "?",
    type_array: $ => seq("[", optional($._expression), "]"),

    type_args: $ => prec(PREC.LIST, choice(
      seq($._type_arg, any_amount_of(",", $._type_arg)),
      $.table_constructor,
    )),
    _type_arg: $ => choice($._type, $._expression),
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
