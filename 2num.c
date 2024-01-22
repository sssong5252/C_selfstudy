#include <stdio.h>

int main() {
    int i;
    scanf("%d", &i);

    int j = 0;
    while (j <= i) {
        if (j % 2 == 0) {
            printf("%d\n", j);
        }
        j++;
    }

    return 0;
}
