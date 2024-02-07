#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, j;
    int len;
    int isPalindrome = 1;

    printf("문자열을 입력하세요: ");
    scanf("%s", str);

    len = strlen(str);

    for (i = 0, j = len - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            isPalindrome = 0;  // 회문이 아님
            break;
        }
    }

    if (isPalindrome) {
        printf("입력한 문자열은 회문입니다.\n");
    } else {
        printf("입력한 문자열은 회문이 아닙니다.\n");
    }

    return 0;
}
