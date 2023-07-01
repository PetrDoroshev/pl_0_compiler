//
// Created by doros on 01.07.2023.
//

#ifndef PL_0_COMPILER_LEXER_H
#define PL_0_COMPILER_LEXER_H

#include "token.h"
#include <unordered_map>
#include <unordered_set>
#include <string>

class Lexer {

private:

    std::unordered_map<std::string, char> key_words {{"const", TOK_CONST},
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

    int value;
    std::string sym;

public:

    char nex_tok();




};

#endif //PL_0_COMPILER_LEXER_H
