#include "parser.h"

void Parser::get_next_token() {

    current_token = lexer.next_token(string_iter);
}

void Parser::expect(Token expected_token) {

    if (current_token != expected_token) {

        error("invalid syntax, line: " + std::to_string(lexer.get_line_number()));
    }

    get_next_token();

}

void Parser::block() {

    if (depth++ > 5) {
        error("nesting depth exceeded");
    }

    if (current_token == TOK_CONST) {
        expect(TOK_CONST);

        if (current_token == TOK_IDENT) {
            sym_tab.add_symbol(TOK_CONST, lexer.get_value(), depth);
        }
        expect(TOK_IDENT);
        expect(TOK_EQUAL);
        expect(TOK_NUMBER);

        while (current_token == TOK_COMMA) {
            expect(TOK_COMMA);

            if (current_token == TOK_IDENT){
                sym_tab.add_symbol(TOK_CONST, lexer.get_value(), depth);
            }

            expect(TOK_IDENT);
            expect(TOK_EQUAL);
            expect(TOK_NUMBER);
        }
        expect(TOK_SEMICOLON);
    }

    if (current_token == TOK_VAR) {

        expect(TOK_VAR);

        if (current_token == TOK_IDENT) {
            sym_tab.add_symbol(TOK_VAR, lexer.get_value(), depth);
        }

        expect(TOK_IDENT);
        while (current_token == TOK_COMMA) {
            expect(TOK_COMMA);

            if (current_token == TOK_IDENT) {
                sym_tab.add_symbol(TOK_VAR, lexer.get_value(), depth);
            }

            expect(TOK_IDENT);
        }
        expect(TOK_SEMICOLON);
    }

    while (current_token == TOK_PROCEDURE) {
        expect(TOK_PROCEDURE);

        if (current_token == TOK_IDENT) {
            sym_tab.add_symbol(TOK_PROCEDURE, lexer.get_value(), depth);
        }

        expect(TOK_IDENT);
        expect(TOK_SEMICOLON);
        block();
        expect(TOK_SEMICOLON);

        sym_tab.destroy_symbols();
    }

    statement();

    if (--depth < 0)
        error("nesting depth fell below 0");

}

void Parser::statement() {

    if (current_token == TOK_IDENT) {
        expect(TOK_IDENT);
        expect(TOK_ASSIGN);
        expression();
    }
    else if (current_token == TOK_CALL) {
        expect(TOK_CALL);
        expect(TOK_IDENT);
    }
    else if (current_token == TOK_BEGIN) {
        expect(TOK_BEGIN);
        statement();
        while (current_token == TOK_SEMICOLON) {
            expect(TOK_SEMICOLON);
            statement();
        }
        expect(TOK_END);
    }
    else if (current_token == TOK_IF) {
        expect(TOK_IF);
        condition();
        expect(TOK_THEN);
        statement();
    }
    else if (current_token == TOK_WHILE) {
        expect(TOK_WHILE);
        condition();
        expect(TOK_DO);
        statement();
    }


}

void Parser::condition() {

    if (current_token == TOK_ODD) {
        expect(TOK_ODD);
        expression();
    }
    else {
        expression();

        switch (current_token) {
            case TOK_EQUAL:
            case TOK_HASH:
            case TOK_LESSTHAN:
            case TOK_GREATERTHAN:
                get_next_token();
                break;
            default:
                error("invalid conditional");
        }
        expression();
    }
}


void Parser::expression() {

    if (current_token == TOK_PLUS || current_token == TOK_MINUS) {
        get_next_token();
    }

    term();

    while (current_token == TOK_PLUS || current_token == TOK_MINUS) {
        get_next_token();
        term();
    }

}

void Parser::term() {

    factor();

    while (current_token == TOK_MULTIPLY || current_token == TOK_DIVIDE) {
        get_next_token();
        factor();
    }
};

void Parser::factor() {


    if (current_token == TOK_IDENT) {
        expect(TOK_IDENT);
    }
    else if (current_token == TOK_NUMBER) {
        expect(TOK_NUMBER);
    }
    else if (current_token == TOK_LPAREN) {
        expect(TOK_LPAREN);
        expression();
        expect(TOK_RPAREN);
    }

}

void Parser::parse() {

    get_next_token();
    block();
    expect(TOK_DOT);
}

void Parser::error(const std::string &msg) {

    std::cout << "Syntax error: " << msg << std::endl;
    exit(1);
}







