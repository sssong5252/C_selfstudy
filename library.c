#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    int bookNumber;
    char title[100];
    char author[100];
    int isBorrowed;
};

struct Library {
    struct Book books[MAX_BOOKS];
    int count;
};

void findBookByNumber(struct Library *library) {
    int bookNumber;
    printf("찾을 도서 번호를 입력하세요: ");
    scanf("%d", &bookNumber);

    int found = 0;
    for (int i = 0; i < library->count; i++) {
        if (library->books[i].bookNumber == bookNumber) {
            printf("도서를 찾았습니다:\n");
            printf("도서 번호: %d\n", library->books[i].bookNumber);
            printf("제목: %s\n", library->books[i].title);
            printf("저자: %s\n", library->books[i].author);
            printf("대출 여부: %s\n", library->books[i].isBorrowed ? "대출 중" : "대출 가능");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("해당 도서를 찾을 수 없습니다.\n");
    }
}

void findBookByAuthor(struct Library *library) {
    char author[100];
    printf("찾을 도서의 저자 이름을 입력하세요: ");
    scanf(" %[^\n]", author);

    int found = 0;
    for (int i = 0; i < library->count; i++) {
        if (strcmp(library->books[i].author, author) == 0) {
            printf("도서를 찾았습니다:\n");
            printf("도서 번호: %d\n", library->books[i].bookNumber);
            printf("제목: %s\n", library->books[i].title);
            printf("저자: %s\n", library->books[i].author);
            printf("대출 여부: %s\n", library->books[i].isBorrowed ? "대출 중" : "대출 가능");
            found = 1;
        }
    }

    if (!found) {
        printf("해당 도서를 찾을 수 없습니다.\n");
    }
}

void findBookByTitle(struct Library *library) {
    char title[100];
    printf("찾을 도서의 제목을 입력하세요: ");
    scanf(" %[^\n]", title);

    int found = 0;
    for (int i = 0; i < library->count; i++) {
        if (strcmp(library->books[i].title, title) == 0) {
            printf("도서를 찾았습니다:\n");
            printf("도서 번호: %d\n", library->books[i].bookNumber);
            printf("제목: %s\n", library->books[i].title);
            printf("저자: %s\n", library->books[i].author);
            printf("대출 여부: %s\n", library->books[i].isBorrowed ? "대출 중" : "대출 가능");
            found = 1;
        }
    }

    if (!found) {
        printf("해당 도서를 찾을 수 없습니다.\n");
    }
}

void addNewBook(struct Library *library) {
    if (library->count >= MAX_BOOKS) {
        printf("더 이상 도서를 추가할 수 없습니다.\n");
        return;
    }

    struct Book newBook;

    printf("도서 번호: ");
    scanf("%d", &newBook.bookNumber);
    printf("제목: ");
    scanf(" %[^\n]", newBook.title);
    printf("저자: ");
    scanf(" %[^\n]", newBook.author);
    newBook.isBorrowed = 0;

    library->books[library->count] = newBook;
    library->count++;

    printf("도서가 추가되었습니다.\n");
}

void displayLibraryCount(struct Library *library) {
    printf("도서관이 소장한 도서의 수: %d\n", library->count);
}

int main(void) {
    struct Library library;
    library.count = 0;

    int choice = -1;

    while (choice != 0) {
        printf("구조체 배열 HARD\n");
        printf("**********\n");
        printf("1. 도서 번호로 책 찾기\n");
        printf("2. 저자 이름으로 책 찾기\n");
        printf("3. 제목으로 책 찾기\n");
        printf("4. 새로운 책 추가\n");
        printf("5. 도서관이 소장한 도서의 수 표시\n");
        printf("메뉴 중 하나를 선택하시오: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                findBookByNumber(&library);
                break;
            case 2:
                findBookByAuthor(&library);
                break;
            case 3:
                findBookByTitle(&library);
                break;
            case 4:
                addNewBook(&library);
                break;
            case 5:
                displayLibraryCount(&library);
                break;
            default:
                printf("잘못된 입력입니다. 다시 입력해주세요.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}
