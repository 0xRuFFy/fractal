#include <stdio.h>

#include "lexer/lexer.h"

int main(void) {
    printf("Hello, World!\n");
    Lexer* lexer = new_lexer("data/lexer_tests/test_1.txt");

    if (lexer == NULL) {
        return 1;
    }

    free_lexer(lexer);
    return 0;
}
