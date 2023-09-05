/*
// // A[][]여기사 앞은 행, 뒤는 열(렬)이다
// #include <stdio.h> //standard input output header file
 
// int main() {
//     // int i=1, sum=0;
 
//     // while (i <= 10) {
//     //     sum += i;
//     //     i++;
//     // }

//     // printf("%d", sum);

//  }

// #include <stdio.h>

// #define NUM_STUDENTS 100

// int main() {
//     int scores[NUM_STUDENTS];
//     int sum = 0;
//     float average;
    
//     printf("100명의 학생 성적을 입력하세요:\n");
    
//     // 학생 성적 입력 받기
//     for (int i = 0; i < NUM_STUDENTS; i++) {
//         printf("학생 %d의 성적: ", i + 1);
//         scanf("%d", &scores[i]);
        
//         sum += scores[i];
//     }
    
//     // 평균 계산
//     average = (float)sum / NUM_STUDENTS;
    
//     // 결과 출력
//     printf("평균 점수: %.2f\n", average);
    
//     return 0;
// }

// #include <stdio.h>
// int main() {
//     int i;
//     int scores[5];
//     int sum = 0;
//     scores[0] = 10;
//     scores[1] = 20;
//     scores[2] = 30;
//     scores[3] = 40;
//     scores[4] = 50;

//     for(i = 0; i < 5; i++) {
//         sum += scores[i];
//         printf("scores[%d] = %d = %d\n", i, scores[i], sum);
//     }
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #define SIZE 5

// int main() {
//     int i;
//     int scores[SIZE];

//     for(i = 0; i < SIZE; i++)
//         scores[i] = rand() % 100;

//     for(i = 0; i < SIZE; i++)
//         printf("scores[%d] = %d\n", i, scores[i]);

//     return 0;
// }
/* #include <stdio.h>
#define STUDENTS 5
int main(void) {
    int scores [STUDENTS];
    int sum=0;
    int i;
    float average;

    for(i = 0; i < STUDENTS; i++) {
        printf("학생들의 성적을 입력하시오: ");
        scanf("%d", &scores[i]);
    }

    for(i = 0; i < STUDENTS; i++)
        sum += scores[i];

    average = (float)sum / STUDENTS;
    printf("성적 평균= %f\n", average);
    
    return 0;
    }*/
// #include <stdio.h>
// int main() {
//     int scores[5] = {31, 63};
//     int i;

//     for(i = 0; i < 5; i++)
//         printf("scores[%d] = %d\n", i, scores[i]);

//     return 0;
// }

// // // // // #include <stdio.h>
// // // // // int main() {
// // // // //     int scores[5] = {31, 63, 62, 87, 14};
// // // // //     int i;

// // // // //     for(i = 0; i < 5; i++)
// // // // //         printf("scores[%d] = %d\n", i, scores[i]);

// // // // //     return 0;
// // // // // }

// // // // // // #include <stdio.h>
// // // // // // int main() {
// // // // // //     int scores[5];
// // // // // //     int i;

// // // // // //     for(i = 0; i < 5; i++)
// // // // // //         printf("scores[%d] = %d\n", i, scores[i]);

// // // // // //     return 0;
// // // // // // }

// // // // // // // #include <stdio.h>
// // // // // // // #include <stdlib.h>
// // // // // // // #define SIZE 6
// // // // // // // int main(void) {
// // // // // // //     int freq[SIZE] = { 0 };
// // // // // // //     int i;
    
// // // // // // //     for(i = 0; i < 10000; i++)
// // // // // // //         ++freq[ rand() % 6 ];

// // // // // // //     printf("====================\n");
// // // // // // //     printf("면 빈도\n");
// // // // // // //     printf("====================\n");
    
// // // // // // //     for(i = 0; i < SIZE; i++)
// // // // // // //         printf("%3d %3d \n", i, freq[i]);
    
// // // // // // //     return 0;
// // // // // // //     }
/* #include <stdio.h>
#define SIZE 5
int main() {
	int i;
	int a[SIZE] = {1, 2, 3, 4, 5};
	int b[SIZE] = {1, 2, 3, 4, 5};
	if(a == b)
		printf("xxx\n");
	else
		printf("xxx\n");

	}
*/

/*#include <stdio.h>
#define s 10
int main() {
	char ans1;
	int ans2, i;
	int seats[s] = {0};

	while(1) {
		print("w")
		scanf("%c", &ans1);
	}
	if(ans1 == 'y') {
		printf("--------------\n");
		printf("12345678910\n");
		printf("--------------\n");
		for(i = 0; i < s; i++)
			printf("%d",seats[i]);
		printf("\n");
		printf("what seat?");
		scanf("&d", &ans2);
	
		if(ans2 <= 0 || ans2 > s){
			printf("1~10");
			continue;
		}
		if(seats[ans2-1] == 0) {
			seats[ans2-1] = 1;
			printf("o")
		}
		else 
			printf("x");
	}

	*/

/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void initializeMatrix(int matrix[ROWS][COLS]) {
    srand(time(NULL)); // 시드값 설정

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % 100; // 0부터 99까지의 난수 생성
        }
    }
}

void printMatrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[ROWS][COLS];

    initializeMatrix(matrix);

    printf("Initialized Matrix:\n");
    printMatrix(matrix);

    return 0;
}
*/

/*#include <stdio.h>
#include <stdbool.h>

#define NUM_SEATS 100

bool seats[NUM_SEATS];

void initializeSeats() {
    for (int i = 0; i < NUM_SEATS; i++) {
        seats[i] = false;
    }
}

void reserveSeat(int seatNumber) {
    if (seatNumber >= 1 && seatNumber <= NUM_SEATS) {
        if (seats[seatNumber - 1]) {
            printf("이미 예약된 자리입니다.\n");
        } else {
            seats[seatNumber - 1] = true;
            printf("자리가 성공적으로 예약되었습니다.\n");
        }
    } else {
        printf("유효하지 않은 자리 번호입니다.\n");
    }
}

void printSeatStatus() {
    printf("영화관 좌석 현황:\n");

    for (int i = 0; i < NUM_SEATS; i++) {
        printf("%d번 좌석: ", i + 1);
        
        if (seats[i]) {
            printf("예약됨\n");
        } else {
            printf("비어있음\n");
        }
    }
}

int main() {
    int seatNumber;

    initializeSeats();

    while (true) { // 무한 반복
        printSeatStatus();

        printf("\n예약할 좌석 번호를 입력하세요 (종료하려면 -1): ");
        scanf("%d", &seatNumber);

        if (seatNumber == -1) { // 종료 조건
            break;
        }

       reserveSeat(seatNumber);
       printf("\n");
   }

   return 0;
}
*/
/*
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define NUM_SEATS 100

bool seats[NUM_SEATS];

void initializeSeats() {
    for (int i = 0; i < NUM_SEATS; i++) {
        seats[i] = false;
    }
}

void reserveSeat(int seatNumber) {
    if (seatNumber >= 1 && seatNumber <= NUM_SEATS) {
        if (seats[seatNumber - 1]) {
            printf("%d번 자리는 이미 예약되었습니다.
", seatNumber);
        } else {
            seats[seatNumber - 1] = true;
            printf("%d번 자리가 성공적으로 예약되었습니다.
", seatNumber);
        }
    } else {
        printf("%d번은 유효하지 않은 자리 번호입니다.
", seatNumber);
    }
}

void reserveMultipleSeats(char* input) {
    char* token = strtok(input, ",");

    while (token != NULL) { // 입력된 모든 토큰에 대해 반복
        int seatNumber = atoi(token); // 문자열을 정수로 변환

        reserveSeat(seatNumber);

        token = strtok(NULL, ",");
    }
}

void printSeatStatus() {
    printf("영화관 좌석 현황:
");

    for (int i = 0; i < NUM_SEATS; i++) {
        printf("%d번 좌석: ", i + 1);

        if (seats[i]) {
            printf("예약됨
");
        } else {
            printf("비어있음
");
        }
    }
}

int main() {
    char input[100];

    initializeSeats();

   while (true) { // 무한 반복
       printSeatStatus();

       printf("
예약할 좌석 번호를 입력하세요 (종료하려면 -1): ");
       fgets(input, sizeof(input), stdin);

       if (strcmp(input, "-1\n") == 0 || strcmp(input, "-1\r\n") == 0) { // 종료 조건
           break;
       }

       input[strcspn(input, "\r\n")] = '\0'; // 개행 문자 제거

       reserveMultipleSeats(input);
       printf("
");
   }

   return 0;
}
*/
/*
#include <stdio.h>
#define SIZE 5

int findMinimum(int array[], int size) {
    int min = array[0];

    for (int i = 1; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }

    return min;
}

int main() {
    int array[SIZE] = {10, 20, 30, 5, 15};
    
    int minimum = findMinimum(array, SIZE);
    
    printf("배열의 최솟값은 %d입니다.", minimum);

    return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

int findMinimum(int array[], int size) {
    int min = array[0];

    for (int i = 1; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }

    return min;
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

    int minimum = findMinimum(array, SIZE);

    printf("배열의 최솟값은 %d입니다.", minimum);

   return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

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
