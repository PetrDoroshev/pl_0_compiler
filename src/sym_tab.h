#ifndef PL_0_COMPILER_SYM_TAB_H
#define PL_0_COMPILER_SYM_TAB_H

#include <string>
#include <iostream>
#include "token.h"

struct SymTabNode {

    int depth;
    Token type;
    std::string name;
    SymTabNode* next;

};


class SymTab {

private:
    SymTabNode* head;

public:

    SymTab();
    void add_symbol(Token type, const std::string& name, int curr_depth);
    void destroy_symbols();

};

#endif //PL_0_COMPILER_SYM_TAB_H
