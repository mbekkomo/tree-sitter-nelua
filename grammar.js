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

    preprocess_name: $ => seq("#|", alias(/[^\|][^#]/, $.lua_expression), "|#"),
    aaa: $ => "",
  }
});
