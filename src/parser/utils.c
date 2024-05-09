#include "parser/utils.h"

ParseTreeNode *__parse_program(Lexer* Lexer) {
    ParseTreeNode* root = (ParseTreeNode*)malloc(sizeof(ParseTreeNode));
    root->type = NODE_PROGRAM;
    root->value = NULL;
    root->num_children = 0;
    root->children = NULL;

    // TODO: Implement parsing logic here

    return root;
}