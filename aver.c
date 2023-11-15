#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};  // 열의 값들을 배열에 저장

    int sum = 0;
    int n = sizeof(arr) / sizeof(arr[0]);  // 배열의 크기 계산

    // 배열의 모든 요소를 합산
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    // 평균 계산
    float average = (float)sum / n;

    printf("열의 평균: %.2f\n", average);

    return 0;
}
