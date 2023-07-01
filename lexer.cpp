//
// Created by doros on 01.07.2023.
//

#include "lexer.h"
#include <cctype>
#include <iostream>

void Lexer::set_value(const std::string &v) {
    value = v;
}

char Lexer::nex_tok(std::string::iterator &it) {

    char token = '\0';

    while (token == '\0') {

        if (*it == ' ' || *it == '\t' || *it == '\n'){
            it++;
        }
        else if (symbols.find(*it) != symbols.end()) {
            token = *it;
            it++;
        }
        else if (*it == ':') {
            if (*(++it) == '=') {
                token = TOK_ASSIGN;
            }
            it++;
        }
        else if (std::isalpha(*it) || *it == '_') {
            token = get_ident(it);
        }
        else if (std::isdigit(*it)) {
            token = get_num(it);
        }
        else if (*it == '\0'){
            return 0;
        }
        else {
            error("Unknown character");
        }

    }

    return token;
}

char Lexer::get_ident(std::string::iterator &it) {

    std::string ident;

    while (std::isalpha(*it)) {
        ident = ident.append(1, *it);
        it++;
    }

    if (key_words.find(ident) != key_words.end()) {
        return key_words[ident];
    }

    set_value(ident);
    return TOK_IDENT;
}

char Lexer::get_num(std::string::iterator &it) {

    std::string num;

    while (std::isdigit(*it)) {
        num = num.append(1, *it);
        it++;
    }

    set_value(num);
    return TOK_NUMBER;

}

std::string Lexer::get_value() {
    return value;
}

void Lexer::error(const std::string& msg) {
    std::cout << "Lexer error: " << msg << std::endl;
    exit(1);
}
