#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// 토큰 타입
typedef enum {
    TOKEN_KEYWORD,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_STRING_LITERAL,
    TOKEN_OPERATOR,
    TOKEN_EOF,
    TOKEN_UNKNOWN
} TokenType;

// 토큰 구조체
typedef struct Token {
    TokenType type;
    char* value;
    struct Token* next;
} Token;

// 키워드 리스트
const char* keywords[] = {
    "if", "else", "while", "for", "return"
};

// 키워드 확인 함수
int isKeyword(const char* str) {
    for (int i = 0; i < sizeof(keywords)/sizeof(char*); i++) {
        if (strcmp(keywords[i], str) == 0) return 1;
    }
    return 0;
}

// 식별자 확인 함수
int isIdentifierChar(char c) {
    return isalpha(c) || c == '_' || isdigit(c);
}

// 숫자 확인 함수
int isNumberChar(char c) {
    return isdigit(c) || c == '.'; // 간단화를 위해, 정수 및 소수점만 고려
}

// 연산자 확인 함수
int isOperatorChar(char c) {
    return strchr("+-*/%=&|<>!", c) != NULL;
}

// 문자열 리터럴 시작/끝 확인 함수
int isStringLiteralStartEnd(char c) {
    return c == '"';
}

// 토큰 생성 함수
Token* createToken(TokenType type, const char* value) {
    Token* token = (Token*)malloc(sizeof(Token));
    token->type = type;
    token->value = strdup(value);
    token->next = NULL;
    return token;
}

// 토큰화 함수
// 이 함수는 매우 기본적이며, 많은 C 언어 구문과 세부 사항을 처리하지 않습니다.
Token* tokenize(const char* src) {
    Token* head = NULL;
    Token* current = NULL;

    while (*src) {
        // 공백 건너뛰기
        if (isspace(*src)) {
            src++;
            continue;
        }

        Token* newToken = NULL;

        // 식별자 또는 키워드
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
        // 숫자
        else if (isdigit(*src)) {
            const char* start = src;
            while (isNumberChar(*src)) src++;
            size_t length = src - start;
            char*


// 토큰 리스트 출력 함수
void printTokens(Token* token) {
    while (token != NULL) {
        printf("Type: %d, Value: %s\n", token->type, token->value);
        Token* temp = token;
        token = token->next;
        free(temp->value); // 동적 할당된 문자열 메모리 해제
        free(temp); // 동적 할당된 토큰 메모리 해제
    }
}

// 메인 함수
int main() {
    char code[] = "int main() { return 0; }";
    Token* tokens = tokenize(code);
    printTokens(tokens);
    return 0;
}

// tokenize 함수와 기타 필요한 함수들을 여기에 정의합니다.
