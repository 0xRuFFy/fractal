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

    // Single character tokens
    TT_LPAREN,
    TT_RPAREN,
    TT_LBRACE,
    TT_RBRACE,
    TT_LBRACKET,
    TT_RBRACKET,
    TT_PLUS,
    TT_MINUS,
    TT_ASTERISK,
    TT_SLASH,
    TT_SEMICOLON,

    // Identifiers
    TT_IDEN,

    // Keywords
    TT_KW_FN,

    // Types (type of keyword)
    TT_TYPE_INT,
    TT_TYPE_FLOAT,
    // TODO: Add i8, i16 etc.

    // Literals
    TT_INT,
    TT_FLOAT,

    // FOR ENUM ASSERTION
    TT_MAX,
} TokenType;

/**
 * @brief Converts a token type to a string.
 * 
 * @param token The token type to convert.
 * 
 * @return The string representation of the token type.
 */
char* token_type_to_string(TokenType token);

/**
 * @brief A token that is a single character.
 */
typedef struct {
    TokenType type;
    char value;
} SingleCharToken;

/**
 * @brief A token that is a keyword.
 */
typedef struct {
    TokenType type;
    const char* value;
    usize value_len;
} KeywordToken;

/**
 * @brief A token produced by the lexer
 *
 * This token contains the type of the token, the value of the token, and the location of the token in the source code.
 */
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
void print_token(const Token* token);

/**
 * @brief Frees the memory used by a token.
 * 
 * @param token The token to free.
 */
void free_token(Token* token);

#endif // TOKEN_H_
