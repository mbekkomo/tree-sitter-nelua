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
};

module.exports = grammar({
  name: "nelua",

  extras: _ => [
    /[\s\r]+/
  ],

  externals: $ => [
    $._start_preproc_name,
    $._end_preproc_name,
    $._start_preproc_expr,
    $._end_preproc_expr,
    $._content_preproc_inline,
  ],

  rules: {
    chunk: $ => $._expression,

    _expression: $ => choice(
      $.number,
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

      return seq(token(choice(decimal_number, hex_number, bin_number)), optional($._identifier));
    },

    table_constructor: $ => seq("{", optional($.field_list), "}"),

    field_list: $ => seq(
      $.field_expression,
      repeatable($._field_separator, $.field_expression),
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

    type: $ => seq("@", $._type),

    _type: $ => choice(
      $.identifier,
      $._id_suffixed,
      $._type_unary,
    ),
    _type_unary: $ => seq(
      choice($.type_pointer, $.type_optional, $.type_array),
      $._type,
    ),
    _type_variants: $ => seq($._type, atleast_amount_of("|", $._type)),
    type_pointer: _ => "*",
    type_optional: _ => "?",
    type_array: $ => seq("[", optional($._expression), "]"),


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

    identifier: $ => choice($._identifier, $._preprocess_name),
    _identifier: _ => /[_a-zA-Z][_a-zA-Z0-9]*/,
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
    _id_suffixed: $ => seq($.identifier, atleast_amount_of(".", $.identifier)),
  },

});

function any_of(...args) {
  return optional(choice(...args));
}

function atleast_amount_of(...args) {
  return repeat1(seq(...args));
}

function repeatable(...args) {
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
