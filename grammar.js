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
    chunk: $ => $._expressions,

    _expressions: $ => choice(
      $.number,
      $.identifier,
      $.nil_literal,
      $.nilptr_literal,
      $.boolean_literal,
      $.varargs,
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

			const decimal_number = seq(
			  decimal_prefix,
			  may_seq(
			    choice("e", "E"),
			    exp_digits,
			  ),
			);

			return token(choice(decimal_number));
		},


    identifier: $ => choice($._identifier),
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

function may_seq(...args) {
  return optional(seq(...args));
}

function either(...args) {
  let choices = [];
  args.forEach(arg => choices.push(seq(...arg)));
  return choice(...choices);
}
