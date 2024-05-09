#ifndef TOKEN_H_
#define TOKEN_H_

#include "defines.h"
#include "lexer/location.h"

/**
 * @brief The different types of tokens that can be found in the source code.
 */
typedef enum {
    // Special tokens
    TT_EOF = 0,
    TT_INVALID,

    // Comments
    TT_SL_COMMENT,
    TT_ML_COMMENT,

    // FOR ENUM ASSERTION
    TT_MAX,
} TokenType;


#define ASSERT_ENUM_TO_STR(sarray, max) typedef char assert_sizeof_##max[(sizeof(sarray)/sizeof((sarray)[0]) == (max)) ? 1 : -1]

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
    Location location;
} Token;

/**
 * @brief Print a token to the console.
 * 
 * @param token The token to print.
 */
void print_token(Token token);

#endif // TOKEN_H_
