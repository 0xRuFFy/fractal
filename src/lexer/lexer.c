#include <stdio.h>
#include <stdlib.h>

#include "lexer/lexer.h"
#include "utils.h"

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
    lexer->line = 1;
    lexer->column = 1;
    lexer->cursor = 0;

    free(source);

    // TODO: REMOVE THIS PRINTF
    printf("File: %s\n", lexer->path);
    printf("File size: %luB\n", lexer->source_length);
    printf("Content: \n%s\n", lexer->source);

    return lexer;
}

void free_lexer(Lexer* lexer) {
    free((void*)lexer->source);
    free(lexer);
}

Token next_token(Lexer* lexer) {
    // TODO: Trim whitespace here
    Token token = {
        .type = TT_EOF,
        .value = lexer->source + lexer->cursor,
        .value_len = 0,
    };

    return token;
}
