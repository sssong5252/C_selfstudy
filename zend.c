#include <stdio.h>

int main()
{
    int z;
    
    do {
        printf("문자열을 입력하세요: ");
        z = getchar();
        
        if (z == 'Z') {
            printf("end");
            break;
        }
        getchar();
    } while (1);
    
    return 0;
}
