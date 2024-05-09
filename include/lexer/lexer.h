#ifndef LEXER_H_
#define LEXER_H_

#include "defines.h"
#include "token.h"

/**
 * @brief The lexer struct.
 */
typedef struct {
    const char* path;
    const char* source;
    usize source_length;
    usize line;
    usize column;
    usize cursor;
} Lexer;

/**
 * @brief Creates a new lexer.
 * 
 * The lexer will read the file at the given path and store the source code in the lexer struct.
 * If the file does not exist or cannot be read, NULL will be returned.
 * 
 * @param file_path The path to the file to lex.
 * 
 * @return The newly created lexer.
 */
Lexer* new_lexer(const char* file_path);

/**
 * @brief Frees the memory allocated for the lexer.
 * 
 * @param lexer The lexer to free.
 */
void free_lexer(Lexer* lexer);

/**
 * @brief Returns the next token in the source code.
 * 
 * @param lexer The lexer to get the next token from.
 * 
 * @return The next token in the source code.
 */
Token next_token(Lexer* lexer);

#endif // LEXER_H_
