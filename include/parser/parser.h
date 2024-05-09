#ifndef PARSE_H_
#define PARSE_H_

#include "lexer/lexer.h"

typedef enum {
    NODE_PROGRAM,

    NODE_FUNC_DECL,

    NODE_PARAM_LIST,
    NODE_STMT,
    NODE_EXPR,
    NODE_TERM,
    NODE_FACTOR,

    NODE_IDEN,
    NODE_INT,
    NODE_FLOAT,
    NODE_STRING,
    NODE_TYPE,
} NodeType;

typedef struct ParseTreeNode ParseTreeNode;

struct ParseTreeNode {
    NodeType type;
    char *value;
    ParseTreeNode **children;
    int num_children;
};

/**
 * @brief Parses the tokens from the lexer into an abstract syntax tree.
 * 
 * @param lexer The lexer to parse tokens from.
 * 
 * @return The root of the abstract syntax tree.
 */
ParseTreeNode *parse(Lexer *lexer);

/**
 * @brief Frees the memory used by a parse tree.
 * 
 * @param root The root of the parse tree to free.
 */
void free_parse_tree(ParseTreeNode *root);

/**
 * @brief Prints a parse tree to the console.
 * 
 * @param root The root of the parse tree to print.
 * @param depth The maximum depth to print the tree to.
 */
void print_parse_tree(ParseTreeNode *root, int depth);

#endif // PARSE_H_