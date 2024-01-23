#include <stdio.h>

int main() {
    int num;
    
    while (1) {
        printf("수를 입력하세요: ");
        scanf("%d", &num);
        
        if (num % 5 == 0) {
            printf("입력한 수는 5의 배수입니다. 프로그램을 종료합니다.\n");
            break;
        }
    }
    
    return 0;
}