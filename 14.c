#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef enum {
    COMIC,
    SF,
    DOCU,
    DRAMA
} GENRE;

struct book {
    char title[100];
    char author[100];
    GENRE type;
};

int main(void) {
    struct book myBook;
    myBook.type = DRAMA;
    strcpy(myBook.title, "바람과 함께 사라지다");
    strcpy(myBook.author, "마가렛 미첼");

    printf("책 제목: %s\n", myBook.title);
    printf("저자: %s\n", myBook.author);
    printf("장르: %d\n", myBook.type);

    return 0;
}
