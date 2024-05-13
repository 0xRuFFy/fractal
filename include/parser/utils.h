#ifndef PARSER_UTILS_H_
#define PARSER_UTILS_H_

#include "lexer/lexer.h"
#include "parser/parser.h"

ParseTreeNode* __iden_to_node(const Token *token);

ParseTreeNode* __parse_program(Lexer *lexer);

ParseTreeNode* __parse_func_decl(Lexer *lexer);

ParseTreeNode* __parse_param_list(Lexer *lexer);

ParseTreeNode* __parse_stmt_list(Lexer *lexer);

#endif  // PARSER_UTILS_H_
