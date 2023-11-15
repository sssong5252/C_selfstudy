#include <stdio.h>

struct student {
    int number;
    char name[10];
    double grade;
};

int main(void) {
    struct student s;
    int count = 0; // 인원수를 저장할 변수

    while (1) {
        printf("학번을 입력하시오 (-1 입력 시 종료): ");
        scanf("%d", &s.number);
        
        // -1이 입력되면 반복문을 종료합니다.
        if (s.number == -1) {
            break;
        }
        
        printf("이름을 입력하시오: ");
        scanf("%s", s.name);
        printf("학점을 입력하시오(실수): ");
        scanf("%lf", &s.grade);
        
        printf("학번: %d\n", s.number);
        printf("이름: %s\n", s.name);
        printf("학점: %f\n", s.grade);
        
        count++; // 인원수를 1 증가시킵니다.
    }

    printf("입력된 인원수: %d\n", count);

    return 0;
}
