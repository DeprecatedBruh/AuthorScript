parser grammar ASParser;

options { tokenVocab=ASLexer; }

program : (statement (NL statement)*)? ;

statement : var
          | function
          | NL
          ;

// Variables
var : ID EQUALS valueType=(VALUE_INT | VALUE_FLOAT | VALUE_STRING | VALUE_TRUE | VALUE_FALSE) #primAssign
    | ID EQUALS LBRACE NL (var NL)* RBRACE #objectAssign
    | ID EQUALS FUNCTION functionParams DO NL functionBody? NL END #functionAssign
    | ID #variable
    ;

// Functions
function : FUNCTION ID functionParams DO NL functionBody? NL END;
functionParams : LPAREN (var (COMMA var)*)? RPAREN ;
functionBody : functionBody (NL functionBody)+
             | statement
             ;
