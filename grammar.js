/**
 * @file A tree-sitter grammar for Nelua
 * @author Komo <afiqquraisyzulkarnain@gmail.com>
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: "nelua",

  extras: _ => [
    /[\s\r]+/
  ],

  externals: $ => [
    $._start_preproc_name,
    $._start_preproc_expr,
    $._content_preproc_inline,
    $._end_preproc_name,
    $._end_preproc_expr,
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
      $.preprocess_expr,
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

    table_constructor: $ => seq("{",  optional($.field_list), "}"),

    field_list: $ => seq(
      $.field_expression,
      repeatable($.field_separator, $.field_expression),
      optional($.field_separator)
    ),
    field_separator: _ => choice(",", ";"),
    field_expression: $ => choice(
      $._field_pair,
      field("key", $._field_sugar_pair),
      field("value", $._expression),
    ),
    _field_sugar_pair: $ => seq("=", $.identifier),
		_field_pair: $ => seq(
		  either(
		    [field("key", $.identifier)],
		    ["[", field("key", $._expression), "]"],
		  ),
		  "=",
		  field("value", $._expression),
		),

    identifier: $ => choice($._identifier, $._preprocess_name),
    _identifier: _ => /[_a-zA-Z][_a-zA-Z0-9]*/,
    _preprocess_name: $ => seq(
      $._start_preproc_name,
      alias($._content_preproc_inline, $.lua_expression),
      $._end_preproc_name,
    ),

    preprocess_expr: $ => seq(
      $._start_preproc_expr,
      alias($._content_preproc_inline, $.lua_expression),
      $._end_preproc_expr,
    ),
  }
});

function any_of(...args) {
  return optional(choice(...args));
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
