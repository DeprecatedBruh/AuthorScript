parser grammar ASParser;

options { tokenVocab=ASLexer; }

program : var* ;

// Variables
var : ID EQUALS valueType=(VALUE_INT | VALUE_FLOAT | VALUE_STRING | VALUE_TRUE | VALUE_FALSE) #variable
    | ID EQUALS LBRACE var* RBRACE #object
    ;