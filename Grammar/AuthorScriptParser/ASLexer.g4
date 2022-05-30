lexer grammar ASLexer;

fragment DIGIT  : [0-9] ;
fragment LETTER : [a-z] | [A-Z] ;
fragment SPCL_CHAR  : [_-] ;
fragment ALPHA_NUM  : DIGIT | LETTER | SPCL_CHAR ;

// Operators
OP_EQUALS : '=' ;
OP_PERIOD : '.' ;
OP_DQOUTE : '"' ;
OP_SQOUTE : '\'' ;

// Values
VALUE_INT : '0'
          | [1-9] DIGIT*
          ;
VALUE_FLOAT   : ('0' | [1-9] DIGIT*)? OP_PERIOD DIGIT* ;
VALUE_TRUE  : 'true' ;
VALUE_FALSE : 'false' ;
VALUE_STRING  : OP_SQOUTE .*? OP_SQOUTE
              | OP_DQOUTE .*? OP_DQOUTE
              ;

// Variables
ID  : ('_' | LETTER) ALPHA_NUM* ;