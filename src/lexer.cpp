#include "lexer.h"
#include <cctype>
#include <iostream>

void Lexer::set_value(const std::string &v) {
    value = v;
}

Token Lexer::next_token(std::string::iterator &it) {

    Token token_type = TOK_EOF;
    set_value("");

    while (token_type == TOK_EOF) {

        if (*it == ' ' || *it == '\t' || *it == '\n'){
            it++;
        }
        else if (symbols.find(*it) != symbols.end()) {
            token_type = (Token)*it;
            it++;
        }
        else if (*it == ':') {
            if (*(++it) == '=') {
                token_type = TOK_ASSIGN;
            }
            it++;
        }
        else if (std::isalpha(*it) || *it == '_') {
            token_type = get_ident(it);
        }
        else if (std::isdigit(*it)) {
            token_type = get_num(it);
        }
        else if (*it == '\0'){
            return TOK_EOF;
        }
        else {
            error("Unknown character: " + std::string(1, *it));
        }

    }

    return token_type;
}

Token Lexer::get_ident(std::string::iterator &it) {

    std::string ident;

    while (std::isalpha(*it) || *it == '_') {
        ident = ident.append(1, (char)std::tolower(*it));
        it++;
    }
    if (key_words.find(ident) != key_words.end()) {
        return key_words[ident];
    }

    set_value(ident);
    return TOK_IDENT;
}

Token Lexer::get_num(std::string::iterator &it) {

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
