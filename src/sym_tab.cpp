#include "sym_tab.h"

SymTab::SymTab() {

    auto* new_node = new SymTabNode;

    new_node->depth = 0;
    new_node->type = TOK_PROCEDURE;
    new_node->name = "main";
    new_node->next = nullptr;

    head = new_node;

}

void SymTab::add_symbol(Token type, const std::string& name, int curr_depth) {

    SymTabNode* curr;
    curr = head;

    while (true) {

        if (curr->name == name && curr->depth == curr_depth - 1) {
            std::cout << ("duplicate symbol: " + name) << std::endl;
            exit(1);
        }

        if (curr->next == nullptr) {
            break;
        }
        curr = curr->next;
    }

    auto* new_node = new SymTabNode;
    new_node->depth = curr_depth - 1;
    new_node->type = type;
    new_node->name = name;
    new_node->next = nullptr;

    curr->next = new_node;

}

void SymTab::destroy_symbols() {

    SymTabNode* curr;
    SymTabNode* prev;

    while (true) {
        curr = head;
        while (curr->next != nullptr) {
            prev = curr;
            curr = curr->next;
        }

        if (curr->type != TOK_PROCEDURE) {
            delete curr;
            prev->next = nullptr;
        }
        else {
            break;
        }
    }
}

