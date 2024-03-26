#include <stdio.h>
#include <string.h>
#include <stdlib.h> // atoi, atof 함수를 사용하기 위한 헤더 파일

int main() {
    char input[] = "int a = 5;";
    char *token;
    char datatype[20];
    char varname[20];
    char value[20];
    int equalsIndex = -1;
    int i;

    // 공백을 기준으로 문자열을 토큰화
    token = strtok(input, " ");

    // 자료형 추출
    strcpy(datatype, token);

    // 변수명 추출
    token = strtok(NULL, " ");
    strcpy(varname, token);

    // 대입 연산자 위치 확인
    for (i = 0; i < strlen(input); i++) {
        if (input[i] == '=') {
            equalsIndex = i;
            break;
        }
    }

    // 대입 연산자 이후 값 추출
    if (equalsIndex != -1) {
        token = strtok(NULL, " ");
        strcpy(value, token);
    }

    // 자료형 확인 후 형변환
    if (strcmp(datatype, "int") == 0) {
        int intValue = atoi(value);
        printf("변수의 자료형은 %s이고, 변수명은 %s이며, 값은 %d입니다.\n", datatype, varname, intValue);
    } else if (strcmp(datatype, "double") == 0) {
        double doubleValue = atof(value);
        printf("변수의 자료형은 %s이고, 변수명은 %s이며, 값은 %f입니다.\n", datatype, varname, doubleValue);
    } else if (strcmp(datatype, "char") == 0) {
        char charValue = value[0];
        printf("변수의 자료형은 %s이고, 변수명은 %s이며, 값은 %c입니다.\n", datatype, varname, charValue);
    } else {
        printf("지원하지 않는 자료형입니다.\n");
    }

    return 0;
}
