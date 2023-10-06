#include <stdio.h>
#include <math.h>

int main() {
    double result = 0.0;
    double number;
    char operator;

    while (1) {
        printf("입력: ");
        scanf("%lf", &number);

        getchar();

        printf("입력: ");
        scanf("%c", &operator);

        if (operator == 'q') {
            printf("계산기를 종료합니다.\n");
            break;
        } else if (operator == '+') {
            double operand;
            printf("입력: ");
            scanf("%lf", &operand);
            result = number + operand;
        } else if (operator == '-') {
            double operand;
            printf("입력: ");
            scanf("%lf", &operand);
            result = number - operand;
        } else if (operator == '*') {
            double operand;
           printf("입력: ");
           scanf("%lf", &operand);
           result = number * operand;
       } else if (operator == '/') {
           double divisor;
           printf("입력: ");
           scanf("%lf", &divisor);

           if (divisor != 0) {
               result = number / divisor;
           } else {
               printf("'0'으로 나누었습니다.\n");
               continue;
          }
      } else if (operator == 'p') {
          double power;
          printf("입력: ");
          scanf("%lf", &power);
          result = pow(number, power);
      } else if (operator == 's') { // 제곱근
          result = sqrt(number);
      } else {
          printf("올바른 연산자를 입력해야 합니다. 현재 입력된 연산자: %c\n", operator);
         continue;
     }

     printf("결과: %f\n", result);
 }

 return 0;
}
