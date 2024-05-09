#include <stdio.h>

#include "parser/parser.h"
#include "parser/utils.h"

ParseTreeNode *parse(Lexer *lexer) {
    if (lexer == NULL) {
        fprintf(stderr, "Something went wrong with the lexer\n");
        return NULL;
    }
    return __parse_program(lexer);
}

void free_parse_tree(ParseTreeNode *root) {
    if (root == NULL) {
        return;
    }

    for (int i = 0; i < root->num_children; i++) {
        free_parse_tree(root->children[i]);
    }

    free(root->children);
    free(root->value);
    free(root);
}

void print_parse_tree(ParseTreeNode *root, int depth) {
    if (root == NULL) {
        return;
    }

    for (int i = 0; i < depth; i++) {
        printf("  ");
    }

    printf("[%-15s] ~ %s\n", node_type_to_string(root->type), root->value);

    for (int i = 0; i < root->num_children; i++) {
        print_parse_tree(root->children[i], depth + 1);
    }
}