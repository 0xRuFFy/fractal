#include "lexer/utils.h"

#include <ctype.h>

bool __cursor_in_bounds(const Lexer* lexer) {
    return lexer->cursor < lexer->source_length;
}

bool __consume_char(Lexer* lexer) {
    lexer->cursor++;
    lexer->column++;
    if (__cursor_in_bounds(lexer) && lexer->source[lexer->cursor] == '\n') {
        lexer->line++;
        lexer->column = 1;
        return true;
    }
    return false;
}

void __trim_whitespace(Lexer* lexer) {
    while (__cursor_in_bounds(lexer) && isspace(lexer->source[lexer->cursor])) {
        __consume_char(lexer);
    }
}