#include <stdio.h>

void print_menu();
void check_menu_num(int a);
void result(int a);

int main()
{
    while (1) {
        print_menu();
    }
    return 0;
}

void print_menu()
{
    int a;
    printf("1. 한줄씩 실행\n");
    printf("2. 전체 실행\n");
    printf("3. 종료\n");
    printf("번호를 입력하세요: ");
    scanf("%d", &a);
    check_menu_num(a);
}

void check_menu_num(int a)
{
    if(a<1 || a>3)
        print_menu();
    else
        result(a);
}

void result(int a)
{
    switch (a) {
        case 1:
            printf("한줄씩 실행\n");
            break;
        case 2:
            printf("전체 실행\n");
            break;
        case 3:
            printf("종료\n");
            break;
        default:
    }
}
