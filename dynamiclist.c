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

    array = (*int/*반횐된 주소값 정수형 포인터 캐스팅*/) malloc(n * sizeof(int)/*필요한 메모리 공간 크기*/); //malloc: 동적으로 메모리 공간 할당

    if(array == NULL) { //메모리 할당 실패
        printf("메모리가 할당되지 않았습니다"); //메모리 할당 실패 == malloc이 null반환
        return 0;
    }

    int i; //반복문
    for(i = 0; i < n; i++){ //0부터 n-1 까지
        array[i] = i + 1;
    }
    //TODO: 배열값 출력
    //free함수 == 할당된 메모리 공간 해제 == 메모리 누수 방지 == malloc이랑 짝처럼 다님
}
//realloc써서 늘어난 만큼 줄어든 만큼 해결해준다.