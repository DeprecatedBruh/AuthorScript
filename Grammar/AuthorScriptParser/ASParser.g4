parser grammar ASParser;

options { tokenVocab=ASLexer; }

program : (statement (NL statement)*)? ;

statement : var
          | function
          | NL
          ;

// Variables
// TODO: Rework variable assignment to be expression based (except for special cases?)
var : ID EQUALS valueType=(VALUE_INT | VALUE_FLOAT | VALUE_STRING | VALUE_TRUE | VALUE_FALSE) #primAssign
    | ID EQUALS LBRACE NL (var NL)* RBRACE #objectAssign
    | ID (COMMA ID)* EQUALS functionCall #functionAssign // Can return to multiple variables
    ;

// Functions
function : FUNCTION ID functionParams DO NL functionBody? NL END
         | ID EQUALS FUNCTION functionParams DO NL functionBody? NL END
         ;
functionParams : LPAREN (ID (COMMA ID)*)? RPAREN ;
functionBody : functionBody (NL functionBody)+
             | statement
             ;
functionCall : ID functionParams ;
