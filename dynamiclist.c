#include <stdio.h> 

//입력받은 갯수만큼 정수 저장
#include <stdlib.h>

int 
main() 
{
    int *array; //포인터변수
    int n; //배열의 크기 저장

    printf("요소의 갯수를 입력하세요: "); //정수값 입력
    scanf("%d", &n);

    array = (int* /*반횐된 주소값 정수형 포인터 캐스팅*/) malloc(n * sizeof(int)/*필요한 메모리 공간 크기*/); //malloc: 동적으로 메모리 공간 할당

    if(array == NULL) { //메모리 할당 실패
        printf("메모리가 할당되지 않았습니다"); //메모리 할당 실패 == malloc이 null반환
        return 0;
    }

    int i; //반복문
    for(i = 0; i < n; i++){ //0부터 n-1 까지
        array[i] = i + 1;
    }

        int movesize;
        printf("추가할 요소 갯수: ");
        scanf("%d", &movesize);

        array = (int*) realloc(array, (n + movesize) * sizeof(int)); //realloc써서 늘어난 만큼 줄어든 만큼 해결해준다.

        if(array == NULL) {
            printf("메모리 재할당 실패!!");
            return 0;
        }

        for(i = 0; i < n + movesize; ++i) { //n+movesize 인 이유 = 길이가 늘어남에 따라 기존의 n에 늘어난 movesize만큼 추가하는 것이다.
            array[i] = i + 1;
        }

        for(i = 0; i < n + movesize; ++i) {
            printf("%d\n", array[i]);
        }

        free(array);//free함수 == 할당된 메모리 공간 해제 == 메모리 누수 방지 == malloc이랑 짝처럼 다님

        return 0;
}