#include <stdio.h>
// int main()
// {
//     int i;
//     char str[4];
//     str[0] = 'a';
//     str[1] = 'b';
//     str[2] = 'c';
//     str[3] = '\0';

//     i = 0;
//     while(str[i] != '\0') {
//         printf("%c",str[i]);
//         i++;
//     }
//     printf("\n");

//     return 0;
// }
// int main()
// {
//     int i = 10;
//     char c = 69;
//     float f = 78;

//     printf("i의 주소: %u\n", &i);
//     printf("c의 주소: %u\n", &c);
//     printf("f의 주소: %u\n", &f);
// }
// int main() {
//     int i = 10;
//     int *p;
//     p = &i;

//     printf("%u, %u\n", p, &i);
// }

// int main()
// {
//     char *qw;

//     qw = (char *)9000;
//     printf("%d\n", qw);

//     qw++;
//     printf("%d\n", qw);
// }

// int main()
// {
//     int  v = 10;
//     int *p;
//     p = &v;
//     v = *p++;
//     printf("%d\n", v);
//     p = &v;
//     v = (*p)++;
//     printf("%d\n", v);
//     p = &v;
//     v = *++p;
//     printf("%d\n",v);
//     p = &v;
//     v = ++*p;
//     printf("%d\n",v);
// }
// #include <stdio.h>
// int main(void)
// {
// int ch; // 정수형에 주의
// while( (ch = getchar()) != EOF )
// putchar(ch);
// return 0;
// }
