#include <stdio.h>
int main() {
    int numbers[10];
    int count = 0;
    int num;

    printf("1부터 5 사이의 수를 10개 입력하세요:\n");

    for (int i = 0; i < 10; i++) {
        scanf("%d", &numbers[i]);
    }

    scanf("%d", &num);
    
    for (int i = 0; i < 10; i++) {
        if (numbers[i] == num) {
            count++;
        }
    }

    printf("배열 안에 %d이 %d개 있습니다.\n",num ,count);

    return 0;
}