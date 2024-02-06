#include <stdio.h>

int main() {
    int number;

    printf("숫자를 입력하세요: ");
    scanf("%d", &number);

    if (number < 0) {
        printf("%d는 음수입니다.\n", number);
        return 0;
    }

    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            printf("%d는 소수가 아닙니다.\n", number);
            return 0;
        }
    }

    printf("%d는 소수입니다.\n", number);

    return 0;
}

