#include <stdio.h>

int main()
{
    int num;
    printf("input: ");
    scanf("%d", &num);
    
    for (int i = 3; i <= num; i += 3) {
        printf("%d ", i);
    }
    
    return 0;
}
