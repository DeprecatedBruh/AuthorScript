lexer grammar ASLexer;

fragment DIGIT  : [0-9] ;
fragment LETTER : [a-z] | [A-Z] ;
fragment SPCL_CHAR  : [_-] ;
fragment ALPHA_NUM  : DIGIT | LETTER | SPCL_CHAR ;

// Strings
DQOUTE : '"' ;
SQOUTE : '\'' ;

// Objects
LBRACE  : '{' ;
RBRACE  : '}' ;

// Operators
EQUALS : '=' ;
PERIOD : '.' ;

// Values
VALUE_INT : '0'
          | [1-9] DIGIT*
          ;
VALUE_FLOAT   : ('0' | [1-9] DIGIT*)? PERIOD DIGIT* ;
VALUE_TRUE  : 'true' ;
VALUE_FALSE : 'false' ;
VALUE_STRING  : SQOUTE .*? SQOUTE
              | DQOUTE .*? DQOUTE
              ;

// Variables
ID  : ('_' | LETTER) ALPHA_NUM* ;

// WS
NL  : '\n' ;
WS  : [ \t] -> skip ;