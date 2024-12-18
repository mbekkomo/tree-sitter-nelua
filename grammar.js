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

    identifier: $ => choice($._identifier, $.preprocess_name),
    _identifier: _ => /[_a-zA-Z][_a-zA-Z0-9]*/,

    preprocess_name: $ => seq($._start_preproc_name, alias($._content_preproc_inline, $.lua_expression), $._end_preproc_name),
  }
});
