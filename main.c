// 원의_넓이_구하는_예제
#include <stdio.h>
int  main(void) {
    float rofcir;
    float areaofcir;
    float ssofcir;

    printf("원의 반지름을 입력하세요: ");
    scanf("%f", &rofcir);

    areaofcir = rofcir * rofcir;
    printf("원의 넓이는 %.2f 입니다.\n", areaofcir);
    return 0;
}