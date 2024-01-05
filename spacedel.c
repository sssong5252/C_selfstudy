// // // // #include <string.h>
// // // // #include <stdio.h>
// // // // #define SIZE 100

// // // // void delete_space(char s[]) {
// // // //     char tmp[SIZE];
// // // //     int i, k = 0;
// // // //     for (i = 0; i < (int)strlen(s); i++) {
// // // //         if (s[i] != ' ')
// // // //             tmp[k++] = s[i];
// // // //     }
// // // //     tmp[k] = '\0';
// // // //     strcpy(s, tmp);
// // // // }

// // // // void print_arr(const char s[]) {
// // // //     for (int i = 0; i < (int)strlen(s); i++) {
// // // //         printf("%c", s[i]);
// // // //     }
// // // //     printf("\n");
// // // // }

// // // // int main(void) {
// // // //     char s[SIZE];
// // // //     fgets(s, SIZE, stdin);
// // // //     if (s[strlen(s) - 1] == '\n')
// // // //         s[strlen(s) - 1] = '\0';
// // // //     delete_space(s);
// // // //     print_arr(s);
// // // //     return 0;
// // // // }

// // // // #include <stdio.h>
// // // // #include <string.h>

// // // // void process_string(const char s[]) {
// // // //     for (int i = 0; s[i] != '\0'; i++) {
// // // //         if (s[i] != ' ')
// // // //             printf("%c", s[i]);
// // // //     }
// // // //     printf("\n");
// // // // }

// // // // int main(void) {
// // // //     char s[100];
// // // //     fgets(s, sizeof(s), stdin);
// // // //     if (s[strlen(s) - 1] == '\n')
// // // //         s[strlen(s) - 1] = '\0';
// // // //     process_string(s);
// // // //     return 0;
// // // // }


// // // #include <stdio.h>
// // // #include <string.h>
// // // void remove_spaces(char* str) {
// // //     int i, j;
// // //     for (i = 0, j = 0; str[i] != '\0'; i++) {
// // //         if (str[i] != ' ') {
// // //             str[j] = str[i];
// // //             j++;
// // //         }
// // //     }
// // //     str[j] = '\0';
// // // }

// // // int main(void) {
// // //     char str[100];
    
// // //     printf("문자열을 입력하세요: ");
// // //     fgets(str, sizeof(str), stdin);
    
// // //     if (str[strlen(str) - 1] == '\n') {
// // //         str[strlen(str) - 1] = '\0';
// // //     }
    
// // //     remove_spaces(str);
    
// // //     printf("공백이 제거된 문자열: %s\n", str);
    
// // //     return 0;
// // // }


// // #include <stdio.h>
// // #include <string.h>

// // void remove_spaces(char str[]) {
// //     int i, j;
// //     for (i = 0, j = 0; str[i] != '\0'; i++) {
// //         if (str[i] != ' ') {
// //             str[j] = str[i];
// //             j++;
// //         }
// //     }
// //     str[j] = '\0';
// // }

// // int main(void) {
// //     char str[100];
    
// //     printf("문자열을 입력하세요: ");
// //     fgets(str, sizeof(str), stdin);
    
// //     // 개행 문자 제거
// //     if (str[strlen(str) - 1] == '\n') {
// //         str[strlen(str) - 1] = '\0';
// //     }
    
// //     remove_spaces(str);
    
// //     printf("공백이 제거된 문자열: %s\n", str);
    
// //     return 0;
// // }

// #include <stdio.h>

// int sumOfDigits(int number) {
//     int sum = 0;
    
//     while (number > 0) {
//         sum += number % 10;  // 가장 오른쪽 자릿수를 더함
//         number /= 10;       // 가장 오른쪽 자릿수를 없애기 위해 10으로 나눔
//     }
    
//     return sum;
// }

// int main() {
//     int num;
    
//     printf("정수를 입력하세요: ");
//     scanf("%d", &num);
    
//     int result = sumOfDigits(num);
    
//     printf("각 자릿수의 합: %d\n", result);
    
//     return 0;
// }

#include <stdio.h>

int main (void)
{
    int cost;
    int money;

    scanf("%d", &cost);
    money = 1000 - cost;

    printf("500원 %d개\n", money / 500);
    money = money % 500;

    printf("100원 %d개\n", money / 100);
    money = money % 100;

    printf("10원 %d개\n", money / 10);
    money = money % 10;
}