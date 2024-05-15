#ifndef FUNC_INFO_H_
#define FUNC_INFO_H_

#include "parser/parser.h"

typedef struct {
    bool is_main;
} FuncInfo;


/**
 * @brief Creates a function info node.
 * 
 * @param lexer The lexer to parse tokens from.
 * 
 * @return The function info node.
 */
FuncInfo* __create_func_info();

#endif  // FUNC_INFO_H_
