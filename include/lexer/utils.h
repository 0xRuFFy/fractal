#ifndef UTILS_H_
#define UTILS_H_

#include "lexer/lexer.h"

/**
 * @brief Check if the cursor is in the bounds of the input string.
 *
 * @param lexer The lexer object.
 * @return true If the cursor is in the bounds of the input string else false.
 */
bool __cursor_in_bounds(const Lexer *lexer);

/**
 * @brief Consume a character from the input string.
 *
 * @param lexer The lexer object.
 * @return true If the next character is a newline character else false.
 */
bool __consume_char(Lexer *lexer);

/**
 * @brief Unconsume a character from the input string.
 *
 * @param lexer The lexer object.
 */
void __unconsume_char(Lexer* lexer);

/**
 * @brief Check if the current character is equal to the input character.
 *
 * @param lexer The lexer object.
 * @param c The character to compare.
 * @return true If the current character is equal to the input character else false.
 */
bool __current_char_is(const Lexer *lexer, char c);

/**
 * @brief Check if the current character is an identifier.
 *
 * @param lexer The lexer object.
 * @param is_first_char If the current character is the first character of the identifier.
 * @return true If the current character is an identifier else false.
 */
bool __current_char_is_iden(const Lexer *lexer, bool is_first_char);

/**
 * @brief Check if the current character is a number.
 *
 * @param lexer The lexer object.
 * @return true If the current character is a number else false.
 */
bool __current_char_is_num(const Lexer *lexer, bool* is_float);

/**
 * @brief Trim whitespace from the input string.
 *
 * Whitespace is determined by the isspace() function from the C standard library.
 *
 * @param lexer The lexer object.
 */
void __trim_whitespace(Lexer *lexer);

/**
 * @brief Creates a token from a single character on the lexer's cursor.
 * 
 * @param lexer The lexer to handle the token with.
 * @param token The token to handle.
 * 
 * @return True if the token was handled, false otherwise.
 */
bool __handle_single_char_token(Lexer* lexer, Token* token);

/**
 * @brief Converts a token to a keyword token if the token value is a keyword.
 * 
 * @param token The token to handle.
 * 
 * @return True if the token was handled, false otherwise.
 */
bool __handle_keyword_token(Token* token);

#endif //UTILS_H_
