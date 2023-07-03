#ifndef PL_0_COMPILER_LEXER_H
#define PL_0_COMPILER_LEXER_H

#include "token.h"
#include <unordered_map>
#include <unordered_set>
#include <string>

class Lexer {

private:

    std::unordered_map<std::string, Token> key_words {{"const", TOK_CONST},
                                                     {"var", TOK_VAR},
                                                     {"procedure", TOK_PROCEDURE},
                                                     {"call", TOK_CALL},
                                                     {"begin", TOK_BEGIN},
                                                     {"end", TOK_END},
                                                     {"if", TOK_IF},
                                                     {"then", TOK_THEN},
                                                     {"while", TOK_WHILE},
                                                     {"do", TOK_DO},
                                                     {"odd", TOK_ODD}};

    std::unordered_set<char> symbols { '.', '=', ',', ';', '#', '<', '>', '+', '-', '*', '/', '(', ')'};

    std::string value;

    void set_value(const std::string& v);
    Token get_ident(std::string::iterator& it);
    Token get_num(std::string::iterator& it);
    static void error(const std::string& msg);

public:

    Token next_token(std::string::iterator& it);
    std::string get_value();

};

#endif //PL_0_COMPILER_LEXER_H
