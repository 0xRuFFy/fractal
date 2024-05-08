#ifndef TOKEN_H_
#define TOKEN_H_

#include "defines.h"
#include "token.h"

/**
 * @brief The different types of tokens that can be found in the source code.
 */
typedef enum {
    // Special tokens
    TT_EOF = 0,
    TT_INVALID,
} TokenType;

/**
 * @brief Converts a token type to a string.
 * 
 * @param token The token type to convert.
 * 
 * @return The string representation of the token type.
 */
char* token_type_to_string(TokenType token);

typedef struct {
    TokenType type;
    const char* value;
    usize value_len;
    // TODO: Add location
} Token;

#endif // TOKEN_H_
