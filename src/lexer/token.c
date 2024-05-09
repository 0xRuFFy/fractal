#include <stdio.h>

#include "lexer/token.h"

char* const TOKEN_TYPE_STRINGS[] = {
    "EOF",
    "INVALID",

    "SL_COMMENT",
    "ML_COMMENT",

    "LPAREN",
    "RPAREN",
    "LBRACE",
    "RBRACE",
    "LBRACKET",
    "RBRACKET",
    "PLUS",
    "MINUS",
    "ASTERISK",
    "SLASH",
    "SEMICOLON",

    "IDEN",

    "KW_FN",

    "TYPE_INT",
    "TYPE_FLOAT",

    "INT",
    "FLOAT",
};

ASSERT_ENUM_ELEMENT_COUNT(TOKEN_TYPE_STRINGS, TT_MAX);

char* token_type_to_string(TokenType token) {
    return TOKEN_TYPE_STRINGS[token];
}

void print_token(Token* token) {
    printf("[%-15s] ~ %-60.*s ", token_type_to_string(token->type), (int)token->value_len, token->value);
    print_location(token->location);
}

void free_token(Token* token) {
    free(token);
}