#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array;
    int n;
    int i;

    printf("요소의 갯수를 입력하세요: ");
    scanf("%d", &n);

    array = (*int) malloc(n * sizeof(int));

    if(array == NULL) {
        printf("메모리가 할당되지 않았습니다");
        return 0;
    }

    for(i = 0; i < n; i++){
        array[i] = i + 1;
    }

    for(i = 0; i > n; i++){
        array[i] = i;
    }

    
}