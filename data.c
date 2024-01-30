#include <stdio.h>

int main() {
    int n;

    printf("정수를 입력하세요 (1-8): ");
    scanf("%d", &n);

    unsigned long long maxValue = 1ULL << (n * 8) - 1;

    printf("%s의 최댓값: %llu\n",
           ((char*[]){"unsigned char", "unsigned short", "unsigned int", "unsigned long", "unsigned long long"})[n-1],
           maxValue);

    return 0;
}

/*
    #include <stdio.h>: 표준 입력과 출력을 위한 헤더 파일을 포함시킵니다.

    int main(): 프로그램의 진입점인 main 함수를 정의합니다.

    int n;: 정수형 변수 n을 선언합니다. 사용자로부터 입력받을 값을 저장할 변수입니다.

    printf("정수를 입력하세요 (1-8): ");: 사용자에게 입력을 요청하는 메시지를 출력합니다.

    scanf("%d", &n);: 사용자로부터 정수를 입력받아 n 변수에 저장합니다.

    unsigned long long maxValue = 1ULL << (n * 8) - 1;: 입력받은 정수 n을 이용하여 해당하는 자료형의 최댓값을 계산합니다. 1ULL은 1을 64비트로 표현하기 위한 부호 없는 long long 자료형의 값입니다. << 연산자를 사용하여 n * 8 비트만큼 왼쪽으로 시프트하고, - 1을 통해 최댓값을 계산합니다.

    printf("%s의 최댓값: %llu\n", ...);: 계산된 최댓값을 출력합니다. %s는 자료형의 이름을, %llu는 최댓값을 출력하기 위한 형식 지정자입니다. (char*[]){"unsigned char", "unsigned short", "unsigned int", "unsigned long", "unsigned long long"})[n-1]을 통해 입력받은 n에 해당하는 자료형의 이름을 가져옵니다.

    return 0;: 프로그램의 종료를 나타내는 0을 반환하고, main 함수를 종료합니다.
 */
