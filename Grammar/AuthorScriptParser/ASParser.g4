parser grammar ASParser;

options { tokenVocab=ASLexer; }

program : variable* ;

// Variables
variable  : ID OP_EQUALS valueType=(VALUE_INT | VALUE_FLOAT | VALUE_STRING | VALUE_TRUE | VALUE_FALSE) ;