#ifndef PARSER_UTILS_H_
#define PARSER_UTILS_H_

#include "lexer/lexer.h"
#include "parser/parser.h"

ParseTreeNode* __parse_program(Lexer *lexer);

#endif  // PARSER_UTILS_H_