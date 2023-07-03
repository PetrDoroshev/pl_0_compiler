#ifndef PL_0_COMPILER_PARSER_H
#define PL_0_COMPILER_PARSER_H

#include "lexer.h"
#include "token.h"

class Parser {

private:

    Lexer lexer();
    char get_next_token();
    static void expect(Token token);

public:

    void parse();

};


#endif //PL_0_COMPILER_PARSER_H
