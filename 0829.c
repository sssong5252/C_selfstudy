// // A[][]여기사 앞은 행, 뒤는 열(렬)이다
// // 
#include <stdio.h>
 
int main() {
    int i=1, sum=0;
 
    while (i <= 10) {
        sum += i;
        i++;
    }

    printf("%d", sum);
}



// #include <stdio.h>
// int main() {
//     int i;
//     int scores[5];

//     scores[0] = 10;
//     scores[1] = 20;
//     scores[2] = 30;
//     scores[3] = 40;
//     scores[4] = 50;

//     for(i = 0; i < 5; i++)
//         printf("scores[%d] = %d\n", i, scores[i]);

//     return 0;
// }

// // #include <stdio.h>
// // #include <stdlib.h>
// // #define SIZE 5

// // int main() {
// //     int i;
// //     int scores[SIZE];

// //     for(i = 0; i < SIZE; i++)
// //         scores[i] = rand() % 100;

// //     for(i = 0; i < SIZE; i++)
// //         printf("scores[%d] = %d\n", i, scores[i]);

// //     return 0;
// // }

// // // #define STUDENTS 5
// // // int main(void) {
// // //     int scores [STUDENTS];
// // //     int sum=0;
// // //     int i, average;

// // //     for(i = 0; i < STUDENTS; i++) {
// // //         printf("학생들의 성적을 입력하시오: ");
// // //         scanf("%d", &scores[i]);
// // //     }

// // //     for(i = 0; i < STUDENTS; i++)
// // //         sum += scores[i];

// // //     average = sum / STUDENTS;
// // //     printf("성적 평균= %d\n", average);
    
// // //     return 0;
// // //     }

// // // // #include <stdio.h>
// // // // int main() {
// // // //     int scores[5] = {31, 63};
// // // //     int i;

// // // //     for(i = 0; i < 5; i++)
// // // //         printf("scores[%d] = %d\n", i, scores[i]);

// // // //     return 0;
// // // // }

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