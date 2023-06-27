#include<stdio.h>
void print_stars()
{
    for(int i = 0; i < 30; i++)
        printf("*");
}

int main(void)
{
    int i;
    print_stars();
    for(int i = 0; i < 32; i++)
        printf(i);
    printf("\nhello world");
    print_stars();
    printf("\n");
    return 0;
}