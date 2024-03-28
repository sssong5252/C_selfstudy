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
        } else if (isdigit(*src)) {
            const char* start = src;
            while (isNumberChar(*src)) src++;
            size_t length = src - start;
            char* str = (char*)malloc(length + 1);
            strncpy(str, start, length);
            str[length] = '\0';
            newToken = createToken(TOKEN_NUMBER, str);
            free(str);
        } else if (isOperatorChar(*src)) {
            char op[2] = {*src, '\0'};
            newToken = createToken(TOKEN_OPERATOR, op);
            src++;
        } else if (isStringLiteralStartEnd(*src)) {
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
        } else if (isOperatorChar(*src)) {
            // 연산자 처리가 이미 위에 있으므로 이 부분은 제거합니다.
        } else {
            char unknown[2] = {*src, '\0'};
            newToken = createToken(TOKEN_UNKNOWN, unknown);
            src++;
        }

        if (head == NULL) {
            head = newToken;
            current = newToken;
        } else if (newToken != NULL) { // NULL 체크 추가
            current->next = newToken;
            current = newToken;
        }
    }
    // 소스 코드의 끝에 도달했습니다. EOF 토큰을 추가합니다.
    if (head != NULL) {
        current->next = createToken(TOKEN_EOF, "EOF");
    } else {
        head = createToken(TOKEN_EOF, "EOF");
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
    const int MAX_CODE_LENGTH = 1024;
    char code[MAX_CODE_LENGTH];

    printf("코드를 입력하세요: ");
    if (fgets(code, MAX_CODE_LENGTH, stdin) == NULL) {
        printf("입력 오류가 발생했습니다.\n");
        return 1;
    }

    // 입력 받은 코드의 마지막에 있는 개행 문자를 제거합니다.
    size_t len = strlen(code);
    if (len > 0 && code[len - 1] == '\n') {
        code[len - 1] = '\0';
    }

    Token* tokens = tokenize(code);
    printTokens(tokens);

    // 할당된 토큰들을 해제합니다.
    while (tokens != NULL) {
        Token* temp = tokens;
        tokens = tokens->next;
        free(temp->value);
        free(temp);
    }

    return 0;
}
