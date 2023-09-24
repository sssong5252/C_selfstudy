#include <stdio.h>

int main() {
    int i, j;

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if ((i >= 1 && i <= 7) && (j == 1))
                printf("0");
            else if ((i == 0 || i == 8) && (j >= 2 && j <=6))
                printf("0");
            else if ((i == 1 || i ==7) && (j >=3 && j <=5))
                printf("0");
            else
                printf("*");
        }
        printf("\n");
    }

    return 0;
}
