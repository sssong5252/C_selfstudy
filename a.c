/*int calculateSum(int num1, int num2) {
    int sum = num1 + num2;
    return sum;
}

int main() {
    int a, b;
    printf("첫 번째 정수를 입력하세요: ");
    scanf("%d", &a);
    printf("두 번째 정수를 입력하세요: ");
    scanf("%d", &b);

    int result = calculateSum(a, b);
    printf("두 정수의 합: %d\n"*
int calculateFactorial(int num) {
    if (num == 0) {
        return 1;
    } else {
        return num * calculateFactorial(num - 1);
    }
}

int main() {
    int n;
    printf("양의 정수를 입력하세요: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("음수는 팩토리얼을 계산할 수 없습니다.\n");
    } else {
        int result = calculateFactorial(n);
        printf("%d의 팩토리얼은 %d입니다.\n", n, result);
    }

    return 0;
}
int calculateFactorial(int num) {
    if (num == 0) {
        return 1;
    } else {
        return num * calculateFactorial(num - 1);
    }
}

int main() {
    int n;
    printf("양의 정수를 입력하세요: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("음수는 팩토리얼을 계산할 수 없습니다.\n");
    } else {
        int result = calculateFactorial(n);
        printf("%d의 팩토리얼은 %d입니다.\n", n, result);
    }
*/
/*int calculateFactorial(int num) {
    if (num == 0) {
        return 1;
    } else {
        return num * calculateFactorial(num - 1);
    }
}

int main() {
    int n;
    printf("양의 정수를 입력하세요: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("음수는 팩토리얼을 계산할 수 없습니다.\n");
    } else {
        int result = calculateFactorial(n);
        printf("%d의 팩토리얼은 %d입니다.\n", n, result);
    }
#include <stdio.h>

double celsiusToFahrenheit(double celsius) {
    double fahrenheit = (celsius * 9 / 5) + 32;
    return fahrenheit;
}

double fahrenheitToCelsius(double fahrenheit) {
    double celsius = (fahrenheit - 32) * 5 / 9;
    return celsius;
}

int main() {
    double temperature;

    printf("온도를 입력하세요: ");
    scanf("%lf", &temperature);

    double convertedToFahrenheit = celsiusToFahrenheit(temperature);
    printf("%.2lf°C는 %.2lf°F입니다.\n", temperature, convertedToFahrenheit);

    double convertedToCelsius = fahrenheitToCelsius(temperature);
    printf("%.2lf°F는 %.2lf°C입니다.\n", temperature, convertedToCelsius);

    return 0;
}*/
#include <stdio.h>
/*
long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

long long calculateCombination(int n, int r) {
    if (r > n)
        return 0;

    long long numerator = factorial(n);
    long long denominator = factorial(r) * factorial(n - r);

    return numerator / denominator;
}

int main() {
    int n, r;
    printf("n을 입력하세요: ");
    scanf("%d", &n);
    printf("r을 입력하세요: ");
    scanf("%d", &r);

    long long result = calculateCombination(n, r);

    printf("%dC%d = %lld\n", n, r, result);

    return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomNumbers(int count) {
    int i;
    for (i = 0; i < count; i++) {
        int randomNumber = rand();
        printf("%d ", randomNumber);
    }
    printf("\n");
}

int main() {
    int count;

    printf("난수의 개수를 입력하세요: ");
    scanf("%d", &count);

    // 시간을 기반으로 시드(seed)를 설정합니다.
    srand(time(0));

    printf("%d개의 난수 생성 결과:\n", count);
    generateRandomNumbers(count);

    return 0;
}

