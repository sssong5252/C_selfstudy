#include <stdio.h>

/* 쉽게 생각해서 호출 스택임
A 다음이 NULL문자인가? = 아니다 = 다음 문자로 이동(A->B)
B 다음이 NULL문자인가? = 아니다 = 다음 문자로 이동(A->B->C)
.
.
E 다음이 NULL문자인가? = 맞다 = 반횐
스택으로 치면 최근이 가장 위에 있으니까
EDCBA가 반환됨
*/

void reverse(const char *str) {
    if (*str == '\0')  //E 다음에는 더 이상 문자가 없으니까 \0(NULL문자) 임. NULL문자 = 문자열의 끝
        return;

    reverse(str + 1);   //이 부분에서 재귀를 호출하는데, A->B->C->D->E->\0
    printf("%c", *str);   //문자 출력 -> 호출 순서의 역순으로
}



int main() {
    reverse("ABCDE");
    return 0;
}