#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

int name() {
    print("20230850 송준용");
}

int findMax(int array[], int size) {
    int max = array[0];

    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    return max;
}

int main() {
    srand(time(NULL)); // 시드값 설정

    int array[SIZE];

    printf("생성된 정수들: ");

    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 100; // 0부터 99까지의 난수 생성
        printf("%d ", array[i]);
    }

    printf("");

    int max = findMax(array, SIZE);

    printf("배열의 최댓값은 %d입니다.", max);

   return 0;
}
