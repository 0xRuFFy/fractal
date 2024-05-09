#include <stdio.h>

#include "lexer/lexer.h"

int main(void) {
    printf("Hello, World!\n");
    Lexer* lexer = new_lexer("data/lexer_tests/test_1.txt");

    if (lexer == NULL) {
        return 1;
    }

    Token token = next_token(lexer);
    while (token.type != TT_EOF) {
        print_token(token);
        token = next_token(lexer);
    }

    free_lexer(lexer);
    return 0;
}
