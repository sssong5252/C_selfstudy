#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef enum {
    TOKEN_KEYWORD,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_STRING_LITERAL,
    TOKEN_OPERATOR,
    TOKEN_EOF,
    TOKEN_UNKNOWN
} TokenType;

typedef struct Token {
    TokenType type;
    char* value;
    struct Token* next;
} Token;

const char* keywords[] = {
    "if", "else", "while", "for", "return"
};

int isKeyword(const char* str) {
    for (int i = 0; i < sizeof(keywords)/sizeof(char*); i++) {
        if (strcmp(keywords[i], str) == 0) return 1;
    }
    return 0;
}

int isIdentifierChar(char c) {
    return isalpha(c) || c == '_' || isdigit(c);
}

int isNumberChar(char c) {
    return isdigit(c) || c == '.';
}

int isOperatorChar(char c) {
    return strchr("+-*/%=&|<>!", c) != NULL;
}

int isStringLiteralStartEnd(char c) {
    return c == '"';
}

Token* createToken(TokenType type, const char* value) {
    Token* token = (Token*)malloc(sizeof(Token));
    token->type = type;
    token->value = strdup(value);
    token->next = NULL;
    return token;
}

Token* tokenize(const char* src) {
    Token* head = NULL;
    Token* current = NULL;

    while (*src) {
        if (isspace(*src)) {
            src++;
            continue;
        }

        Token* newToken = NULL;

        if (isalpha(*src) || *src == '_') {
            const char* start = src;
            while (isIdentifierChar(*src)) src++;
            size_t length = src - start;
            char* str = (char*)malloc(length + 1);
            strncpy(str, start, length);
            str[length] = '\0';

            if (isKeyword(str)) {
                newToken = createToken(TOKEN_KEYWORD, str);
            } else {
                newToken = createToken(TOKEN_IDENTIFIER, str);
            }
            free(str);
        }

        else if (isdigit(*src)) {
            const char* start = src;
            while (isNumberChar(*src)) src++;
            size_t length = src - start;
            char* str = (char*)malloc(length + 1);
            strncpy(str, start, length);
            str[length] = '\0';
            newToken = createToken(TOKEN_NUMBER, str);
            free(str);
        }
        else if (isOperatorChar(*src)) {
            char op[2] = {*src, '\0'};
            newToken = createToken(TOKEN_OPERATOR, op);
            src++;
        }
        else if (isStringLiteralStartEnd(*src)) {
            src++; // 문자열 리터럴 시작 부분 건너뛰기
            const char* start = src;
            while (!isStringLiteralStartEnd(*src) && *src != '\0') src++;
            if (*src == '\0') {
                // 오류 처리: 문자열 리터럴이 닫히지 않음
                // 여기서 오류 처리 로직을 추가할 수 있습니다.
                break;
            }
            size_t length = src - start;
            char* str = (char*)malloc(length + 1);
            strncpy(str, start, length);
            str[length] = '\0';
            newToken = createToken(TOKEN_STRING_LITERAL, str);
            free(str);
            src++; // 문자열 리터럴 끝 부분 건너뛰기
        }

            if (head == NULL) {
                head = newToken;
                current = newToken;
            } else {
                current->next = newToken;
                current = newToken;
            }
        } else {
            // 여기서는 알려진 모든 토큰 유형에 대한 처리가 완료되었습니다.
            // 만약 여기에 도달했다면, 알 수 없는 문자 또는 처리되지 않은 문자를 만난 것입니다.
            // 이 경우 TOKEN_UNKNOWN 유형의 토큰을 생성할 수 있습니다.
            char unknown[2] = {*src, '\0'};
            newToken = createToken(TOKEN_UNKNOWN, unknown);
            src++;

            if (head == NULL) {
                head = newToken;
                current = newToken;
            } else {
                current->next = newToken;
                current = newToken;
            }
        }
    }
    // 소스 코드의 끝에 도달했습니다. EOF 토큰을 추가합니다.
    Token* eofToken = createToken(TOKEN_EOF, "EOF");
    if (head == NULL) {
        head = eofToken;
    } else {
        current->next = eofToken;
    }
    return head;
}

void printTokens(Token* token) {
    while (token != NULL) {
        printf("Type: %d, Value: %s\n", token->type, token->value);
        Token* temp = token;
        token = token->next;
        free(temp->value);
        free(temp);
    }
}

int main() {
    char code[] = "int main() { return 0; }";
    Token* tokens = tokenize(code);
    printTokens(tokens);
    return 0;
}
