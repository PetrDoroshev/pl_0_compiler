#ifndef PL_0_COMPILER_PARSER_H
#define PL_0_COMPILER_PARSER_H

#include <iostream>
#include "lexer.h"
#include "token.h"

class Parser {

private:

    Lexer lexer;
    Token current_token;
    std::string::iterator string_iter;
    int depth = 0;

    void get_next_token();

    void expect(Token expected_token);

    static void error(const std::string& msg);

    void block();

    void statement();

    void expression();

    void condition();

    void term();

    void factor();

public:

    void parse();

    Parser(std::string::iterator& it) {
        string_iter = it;
        current_token = TOK_EOF;

    }
};


#endif //PL_0_COMPILER_PARSER_H
