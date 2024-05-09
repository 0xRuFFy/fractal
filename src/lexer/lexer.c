#include <stdio.h>
#include <stdlib.h>

#include "lexer/lexer.h"
#include "lexer/token.h"
#include "utils.h"
#include "lexer/utils.h"

Lexer* new_lexer(const char* file_path) {
    Lexer* lexer = malloc(sizeof(Lexer));

    String* source = read_file(file_path);

    if (source == NULL) {
        free(lexer);
        return NULL;
    }

    lexer->path = file_path;
    lexer->source = source->start;
    lexer->source_length = source->length;
    lexer->line = 0;
    lexer->column = 0;
    lexer->cursor = 0;

    free(source);

    // TODO: REMOVE THIS PRINTF
    printf("File: %s\n", lexer->path);
    printf("File size: %luB\n", lexer->source_length);
    printf("Content: \n%s", lexer->source);

    return lexer;
}

void free_lexer(Lexer* lexer) {
    free((void*)lexer->source);
    free(lexer);
}

Token* next_token(Lexer* lexer) {
    __trim_whitespace(lexer);

    Token* token = malloc(sizeof(Token));
    token->type = TT_EOF;
    token->value = lexer->source + lexer->cursor;
    token->value_len = 0;
    token->location.file_path = lexer->path;
    token->location.line = lexer->line + 1;
    token->location.column = lexer->column;

    if (token->location.line == 1 && token->location.column == 0) {
        token->location.column = 1;
    }

    if (!__cursor_in_bounds(lexer)) {
        return token;
    }

    // Handle Comments
    if (__current_char_is(lexer, '/')) {
        __consume_char(lexer);
        token->value_len++;
        if (__cursor_in_bounds(lexer) && __current_char_is(lexer, '/')) {
            token->type = TT_SL_COMMENT;
            while (__cursor_in_bounds(lexer) && !__consume_char(lexer)) {
                token->value_len++;
            }

            return token;
        }
        if (__cursor_in_bounds(lexer) && __current_char_is(lexer, '*')) {
            token->type = TT_ML_COMMENT;
            bool found_asterisk = false;
            while (__cursor_in_bounds(lexer)) {
                if (found_asterisk && __current_char_is(lexer, '/')) {
                    __consume_char(lexer);
                    token->value_len++;
                    break;
                }
                if (__current_char_is(lexer, '*')) {
                    found_asterisk = true;
                } else {
                    found_asterisk = false;
                }
                __consume_char(lexer);
                token->value_len++;
            }

            return token;
        }

        __unconsume_char(lexer);
        token->value_len--;
    }

    // Handle Identifiers
    if (__current_char_is_iden(lexer, true)) {
        token->type = TT_IDEN;
        while (__cursor_in_bounds(lexer) && __current_char_is_iden(lexer, false)) {
            __consume_char(lexer);
            token->value_len++;
        }

        // Handle Keywords
        __handle_keyword_token(token);

        return token;
    }

    // Handle Literals (Integers, Floats, Strings, ...)
    bool is_float = false;
    if (__current_char_is_num(lexer, &is_float)) {
        while (__cursor_in_bounds(lexer) && __current_char_is_num(lexer, &is_float)) {
            __consume_char(lexer);
            token->value_len++;
        }

        token->type = is_float ? TT_FLOAT : TT_INT;
        return token;
    }

    // Handle Multi-character tokens
    
    // Handle Single-character tokens
    if (__handle_single_char_token(lexer, token)) {
        return token;
    }


    token->type = TT_INVALID;
    __consume_char(lexer);
    token->value_len++;

    return token;
}
