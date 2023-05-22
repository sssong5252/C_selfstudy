/*#include <stdio.h>
int main(void)
{
    int number;

    printf("정수를 입력하세요");
    scanf("%d", &number);

    if( number > 0)
        printf("양수입니다\n");

    if( number < 0)
        printf("음수입니다\n");

    printf("입력값은 %d 입니다\n", number);
    return 0;
}*/

#include <stdio.h>
int main(void)
{
    float x;
    float y;
    char sss;

    printf("a: ");
    scanf("%f", &x);

    printf("b: ");
    scanf("%f", &y);

    printf("연산: ");
    scanf("%s", &sss);

    if(sss == '+')
        printf("%.1f + %.1f = %.2f\n", x, y, x + y);

    if(sss == 'x')
        printf("%.1f x %.1f = %.2f\n", x, y, x * y);

    if(sss == '/')
        printf("%.1f / %.1f = %.2f\n", x, y, x / y);
    
    if(sss == '-')
        printf("%.1f - %.1f = %f.2\n", x, y, x - y);

    return 0;
}
