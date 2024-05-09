#include <ctype.h>
#include <string.h>

#include "lexer/utils.h"
#include "lexer/token.h"

SingleCharToken single_char_tokens[] = {
    { TT_LPAREN, '(' },
    { TT_RPAREN, ')' },
    { TT_LBRACE, '{' },
    { TT_RBRACE, '}' },
    { TT_LBRACKET, '[' },
    { TT_RBRACKET, ']' },
    { TT_PLUS, '+' },
    { TT_MINUS, '-' },
    { TT_ASTERISK, '*' },
    { TT_SLASH, '/' },
    { TT_SEMICOLON, ';' },
};

KeywordToken const keyword_tokens[] = {
    { TT_KW_FN, "fn", 2 },
    { TT_TYPE_INT, "int", 3 },
    { TT_TYPE_FLOAT, "float", 5 },
};

#ifndef SC_TOKEN_COUNT
#define SC_TOKEN_COUNT ARRAY_LENGTH(single_char_tokens)
#endif // SC_TOKEN_COUNT

#ifndef KW_TOKEN_COUNT
#define KW_TOKEN_COUNT ARRAY_LENGTH(keyword_tokens)
#endif // KW_TOKEN_COUNT

bool __cursor_in_bounds(const Lexer* lexer) {
    return lexer->cursor < lexer->source_length;
}

bool __consume_char(Lexer* lexer) {
    lexer->cursor++;
    lexer->column++;
    if (__cursor_in_bounds(lexer) && lexer->source[lexer->cursor-1] == '\n') {
        lexer->line++;
        lexer->column = 0;
        return true;
    }
    return false;
}

void __unconsume_char(Lexer* lexer) {
    lexer->cursor--;
    lexer->column--;
    if (__cursor_in_bounds(lexer) && lexer->source[lexer->cursor] == '\n') {
        lexer->line--;
        lexer->column = 0;
    }
}

bool __current_char_is(const Lexer *lexer, const char c) {
    return lexer->source[lexer->cursor] == c;
}

bool __current_char_is_iden(const Lexer *lexer, const bool is_first_char) {
    return __current_char_is(lexer, '_') || (is_first_char ? isalpha(lexer->source[lexer->cursor]) : isalnum(lexer->source[lexer->cursor]));
}

bool __current_char_is_num(const Lexer *lexer, bool* is_float) {
    const char c = lexer->source[lexer->cursor];
    if (isdigit(c)) {
        return true;
    }
    if (c == '.' && !*is_float) {
        *is_float = true;
        return true;
    }
    return false;
}


void __trim_whitespace(Lexer* lexer) {
    while (__cursor_in_bounds(lexer) && isspace(lexer->source[lexer->cursor])) {
        __consume_char(lexer);
    }
}

bool __handle_single_char_token(Lexer *lexer, Token *token) {
    for (usize i = 0; i < SC_TOKEN_COUNT; i++) {
        SingleCharToken const sct = single_char_tokens[i];
        if (__current_char_is(lexer, sct.value)) {
            token->type = sct.type;
            token->value_len = 1;
            __consume_char(lexer);
            return true;
        }
    }
    return false;
}

bool __handle_keyword_token(Token *token) {
    for (usize i = 0; i < KW_TOKEN_COUNT; i++) {
        const KeywordToken kt = keyword_tokens[i];
        if (strncmp(token->value, kt.value, kt.value_len) == 0) {
            token->type = kt.type;
            token->value_len = kt.value_len;
            return true;
        }
    }
    return false;
}
