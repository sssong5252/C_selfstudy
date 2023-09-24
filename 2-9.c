#include <stdio.h>

int main() {
    printf("20230850 컴퓨터공학과 송준용\n");
    int i, j;
    for (i = 2; i <= 9; i++) {
        printf("=== %d단 ===\n", i);
        for (j = 1; j <= 9; j++) {
            printf("%d * %d = %d\n", i, j, i*j);
        }
        printf("\n");
    }
    return 0;
}

