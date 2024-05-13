#define _CRT_SECURE_NO_WARNINGS

#include "lexer/lexer.h"
#include <stdio.h>
#include <string.h>

#include "parser/utils.h"
#include "lexer/token.h"


void __add_child(ParseTreeNode* parent, ParseTreeNode* child) {
    parent->num_children++;
	void* tmp = realloc(parent->children, parent->num_children * sizeof(ParseTreeNode*));
	if (tmp == NULL) {
		fprintf(stderr, "Failed to allocate memory for children\n");
		exit(1);
	}
	parent->children = (ParseTreeNode**)tmp;
    parent->children[parent->num_children - 1] = child;
}

ParseTreeNode* __iden_to_node(const Token* token) {
    ParseTreeNode* node = malloc(sizeof(ParseTreeNode));
	if (node == NULL) {
		fprintf(stderr, "Failed to allocate memory for node\n");
		exit(1);
	}
    node->type = NODE_IDEN;
    node->value = (char*)malloc(token->value_len + 1);
	if (node->value == NULL) {
		fprintf(stderr, "Failed to allocate memory for node value\n");
		exit(1);
    }
    strncpy(node->value, token->value, token->value_len);
    node->value[token->value_len] = '\0';
    node->num_children = 0;
    node->children = NULL;
    return node;
}

ParseTreeNode *__parse_program(Lexer* lexer) {
    ParseTreeNode* root = malloc(sizeof(ParseTreeNode));
	if (root == NULL) {
		fprintf(stderr, "Failed to allocate memory for root node\n");
		exit(1);
	}
    root->type = NODE_PROGRAM;
    root->value = NULL;
    root->num_children = 0;
    root->children = NULL;

    // TODO: Implement parsing logic here

    while (!token_is(peek_token(lexer), TT_EOF)){
        const Token* token = next_token(lexer);
        switch (token->type) {
            case TT_EOF:
                break;
            case TT_KW_FN:
                __add_child(root, __parse_func_decl(lexer));
                break;
            default:
                fprintf(stderr, "Unexpected token: ");
                print_token(stderr, token);
                exit(1);
        }
    }

    return root;
}

ParseTreeNode *__parse_func_decl(Lexer* lexer) {
    ParseTreeNode* node = malloc(sizeof(ParseTreeNode));
	if (node == NULL) {
		fprintf(stderr, "Failed to allocate memory for node\n");
		exit(1);
	}
    node->type = NODE_FUNC_DECL;
    node->value = NULL;
    node->num_children = 0;
    node->children = NULL;

    // TODO: Implement parsing logic here
    const Token* token = next_token(lexer);

    if (!token_is(token, TT_IDEN)) {
        fprintf(stderr, "Expected identifier, got: ");
        print_token(stderr, token);
        exit(1);
    }

    __add_child(node, __iden_to_node(token));
    token = next_token(lexer);

    if (!token_is(token, TT_LPAREN)) {
        fprintf(stderr, "Expected '(', got: ");
        print_token(stderr, token);
        exit(1);
    }

    __add_child(node, __parse_param_list(lexer));
    token = next_token(lexer);

    if (!token_is(token, TT_RPAREN)) {
        fprintf(stderr, "Expected ')', got: ");
        print_token(stderr, token);
        exit(1);
    }

    token = next_token(lexer);

    if (!token_is(token, TT_LBRACE)) {
        fprintf(stderr, "Expected '{', got: ");
        print_token(stderr, token);
        exit(1);
    }

    __add_child(node, __parse_stmt_list(lexer));
    token = next_token(lexer);
    
    if (!token_is(token, TT_RBRACE)) {
        fprintf(stderr, "Expected '}', got: ");
        print_token(stderr, token);
        exit(1);
    }

    return node;
}

ParseTreeNode *__parse_param_list(Lexer* lexer) {
    ParseTreeNode* node = malloc(sizeof(ParseTreeNode));
    if (node == NULL) {
		fprintf(stderr, "Failed to allocate memory for node\n");
		exit(1);
    }
    node->type = NODE_PARAM_LIST;
    node->value = NULL;
    node->num_children = 0;
    node->children = NULL;

    // TODO: Implement parsing logic here

    return node;
}

ParseTreeNode *__parse_stmt_list(Lexer* lexer) {
    ParseTreeNode* node = malloc(sizeof(ParseTreeNode));
	if (node == NULL) {
		fprintf(stderr, "Failed to allocate memory for node\n");
		exit(1);
	}
    node->type = NODE_STMT_LIST;
    node->value = NULL;
    node->num_children = 0;
    node->children = NULL;

    // TODO: Implement parsing logic here
    
    return node;
}
