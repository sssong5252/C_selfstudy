#include <stdio.h>
#include <string.h>

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

int equal_author(struct book b1, struct book b2) {
    if (strcmp(b1.author, b2.author) == 0) {
        return 1; // 저자가 일치하는 경우 1 반환
    } else {
        return 0; // 저자가 일치하지 않는 경우 0 반환
    }
}

int main(void) {
    struct book b1 = { "노인과 바다", "헤밍웨이", DRAMA };
    struct book b2 = { "누구를 위하여 종을 울리나", "헤밍웨이", DRAMA };

    int result = equal_author(b1, b2);

    printf("equal_author()의 반환값: %d\n", result);

    return 0;
}
