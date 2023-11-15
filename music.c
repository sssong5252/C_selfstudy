#include <stdio.h>
#include <string.h>

#define MAX_SONGS 100

typedef enum {
    KPOP,
    POP,
    CLASSICAL,
    MOVIE_SOUNDTRACK
} Genre;

struct Song {
    char title[100];
    char artist[100];
    char file_path[100];
    Genre genre;
};

struct Database {
    struct Song songs[MAX_SONGS];
    int count;
};

void addSong(struct Database *db) {
    if (db->count >= MAX_SONGS) {
        printf("더 이상 음악을 추가할 수 없습니다.\n");
        return;
    }

    struct Song newSong;

    printf("제목: ");
    scanf(" %[^\n]", newSong.title);
    printf("가수: ");
    scanf(" %[^\n]", newSong.artist);
    printf("파일 경로: ");
    scanf(" %[^\n]", newSong.file_path);
    printf("장르(0: 가요, 1: 팝, 2: 클래식, 3: 영화음악): ");
    scanf("%d", &(newSong.genre));

    db->songs[db->count] = newSong;
    db->count++;

    printf("음악이 추가되었습니다.\n");
}

void printSongs(struct Database *db) {
    if (db->count == 0) {
        printf("등록된 음악이 없습니다.\n");
        return;
    }

    printf("등록된 음악 목록:\n");
    for (int i = 0; i < db->count; i++) {
        printf("제목: %s\n", db->songs[i].title);
        printf("가수: %s\n", db->songs[i].artist);
        printf("파일 경로: %s\n", db->songs[i].file_path);
        printf("장르: %d\n", db->songs[i].genre);
        printf("**********\n");
    }
}

void searchSong(struct Database *db) {
    if (db->count == 0) {
        printf("등록된 음악이 없습니다.\n");
        return;
    }

    char searchTitle[100];
    printf("검색할 음악의 제목을 입력하세요: ");
    scanf(" %[^\n]", searchTitle);

    int found = 0;
    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->songs[i].title, searchTitle) == 0) {
            printf("음악을 찾았습니다:\n");
            printf("제목: %s\n", db->songs[i].title);
            printf("가수: %s\n", db->songs[i].artist);
            printf("파일 경로: %s\n", db->songs[i].file_path);
            printf("장르: %d\n", db->songs[i].genre);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("해당 음악을 찾을 수 없습니다.\n");
    }
}

int main(void) {
    struct Database musicDB;
    musicDB.count = 0;

    int choice = -1;

    while (choice != 4) {
        printf("구조체 배열 HARD\n");
        printf("**********\n");
        printf("1. 추가\n");
        printf("2. 출력\n");
        printf("3. 검색\n");
        printf("4. 종료\n");
        printf("정수값을 입력하시오: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSong(&musicDB);
                break;
            case 2:
                printSongs(&musicDB);
                break;
            case 3:
                searchSong(&musicDB);
                break;
            case 4:
                printf("프로그램을 종료합니다.\n");
                break;
            default:
                printf("잘못된 입력입니다. 다시 입력해주세요.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}
