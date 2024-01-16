#include <stdio.h>

int main() {
    int i = 0;
    scanf("%d", &i);

    if (i == 1) {
        printf("*\n");
        return 0;
    }

    for (int j = 0; j < i; j++) {
        for (int k = 0; k < i - j; k++) {
            printf(" ");
        }

        for (int h = 0; h < j; h++) {
            printf("*");
        }

        for (int g = 0; g < j - 1; g++) {
            printf("*");
        }

        printf("\n");
    }

    if (i == 2) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < i + 1; k++) {
                printf("*");
            }
            printf("\n");
        }
    } else {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < i + 2 * (i - 2); k++) {
                printf("*");
            }
            printf("\n");
        }
    }

    for (int j = 0; j < i; j++) {
        for (int k = 0; k < j + 1; k++) {
            printf(" ");
        }
        for (int k = 0; k < i - j - 1; k++) {
            printf("*");
        }
        for (int k = 0; k < i - j - 2; k++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
