lexer grammar ASLexer;

@lexer::members { 
  bool ignoreNewlines() const {
    return paren_nesting > 0;
  }
  // Members
  unsigned long long int paren_nesting = 0;
}

fragment DIGIT : [0-9] ;
fragment LETTER : [a-z] | [A-Z] ;
fragment SPCL_CHAR : [_-] ;
fragment ALPHA_NUM : DIGIT | LETTER | SPCL_CHAR ;

// Strings
DQOUTE : '"' ;
SQOUTE : '\'' ;

// Objects
LBRACE : '{' ;
RBRACE : '}' ;

// Operators
EQUALS : '=' ;
PERIOD : '.' ;

// Values
VALUE_INT : '0'
          | [1-9] DIGIT*
          ;
VALUE_FLOAT : ('0' | [1-9] DIGIT*)? PERIOD DIGIT* ;
VALUE_TRUE : 'true' ;
VALUE_FALSE : 'false' ;
VALUE_STRING : SQOUTE .*? SQOUTE
             | DQOUTE .*? DQOUTE
             ;

// Variables
ID : ('_' | LETTER) ALPHA_NUM* ;

// Functions
FUNCTION : 'function' ;
LPAREN : '(' { paren_nesting++; } ;
RPAREN : ')' { paren_nesting--; } ;
COMMA : ',' ;

// Conditionals, Functions & Loops
DO  : 'do' ;
END : 'end' ;

// WS
fragment NL_FRAG : '\r'? '\n' ;
IGNORE_NL : NL_FRAG { ignoreNewlines() }? -> skip ;
NL : NL_FRAG ;
WS : [ \t] -> skip ;