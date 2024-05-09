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
 * @brief Trim whitespace from the input string.
 *
 * Whitespace is determined by the isspace() function from the C standard library.
 *
 * @param lexer The lexer object.
 */
void __trim_whitespace(Lexer *lexer);

#endif //UTILS_H_
