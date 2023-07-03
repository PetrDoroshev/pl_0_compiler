#ifndef PL_0_COMPILER_TOKEN_H
#define PL_0_COMPILER_TOKEN_H

enum Token {

    TOK_IDENT =	    'I',
    TOK_NUMBER =	'N',
    TOK_CONST =	    'C',
    TOK_VAR =		'V',
    TOK_PROCEDURE = 'P',
    TOK_CALL =	    'c',
    TOK_BEGIN =	    'B',
    TOK_END =		'E',
    TOK_IF =		'i',
    TOK_THEN =	    'T',
    TOK_WHILE =	    'W',
    TOK_DO =		'D',
    TOK_ODD =		'O',
    TOK_DOT =		'.',
    TOK_EQUAL =	    '=',
    TOK_COMMA =	    ',',
    TOK_SEMICOLON =	';',
    TOK_ASSIGN =	':',
    TOK_HASH =	    '#',
    TOK_LESSTHAN =	'<',
    TOK_GREATERTHAN =   '>',
    TOK_PLUS =	    '+',
    TOK_MINUS =	    '-',
    TOK_MULTIPLY =	'*',
    TOK_DIVIDE =	'/',
    TOK_LPAREN =	'(',
    TOK_RPAREN =	')',
    TOK_EOF =       '\0'

};




#endif //PL_0_COMPILER_TOKEN_H
