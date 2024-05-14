#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

typedef struct Line
{
    char kor[1024];
    char eng[1024];
    struct Line *next;
} Line;

Line *head = NULL;

int size()
{
    int count = 0;
    Line *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}


void shuffleLines() {

  srand(time(NULL));  

  int n = size();
  if(n <= 1) return;  

  Line* current = head;

  for(int i=0; i<n-1; i++) {
    
    int randIdx = rand() % n;

    Line* move = head;
    for(int j=0; j<randIdx; j++) {
      move = move->next; 
    }

    // 데이터 교환
    char tempKor[1024], tempEng[1024];

    strcpy(tempKor, current->kor);
    strcpy(tempEng, current->eng);

    strcpy(current->kor, move->kor); 
    strcpy(current->eng, move->eng);
    
    strcpy(move->kor, tempKor);
    strcpy(move->eng, tempEng);

    current = current->next; 
  }

}

void insertLine(int lineNumber, char *kor, char *eng) {

    Line *newLine = (Line *)malloc(sizeof(Line));
    strcpy(newLine->kor, kor);
    strcpy(newLine->eng, eng);

    if (lineNumber == 1) {
        newLine->next = head;
        head = newLine;
    } else {
        Line *temp = head;
        Line *prev = NULL;
        int i = 1;

        while(i < lineNumber && temp != NULL) {
            prev = temp;
            temp = temp->next;
            i++;
        }
        
        if(prev != NULL) {
            newLine->next = prev->next;
            prev->next = newLine;
        } else {
            printf("Invalid line number\n");
        }
    }

}


void deleteLine(int lineNumber)
{
    Line *temp = head, *prev = NULL;
    int count = 1;

    if (lineNumber == 1)
    {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && count < lineNumber)
    {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
    {
        printf("Line does not exist.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void updateLine(int lineNumber, char *newKor, char *newEng)
{
    Line *temp = head;
    int count = 1;

    while (temp != NULL && count < lineNumber)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
    {
        printf("Line does not exist.\n");
        return;
    }

    strcpy(temp->kor, newKor);
    strcpy(temp->eng, newEng);
}

void printLines() {

  if(head == NULL) {
    printf("Line is empty!\n");
    return;
  }

  Line *temp = head; 
  int count = 1;

  while(temp != NULL) {
    printf("%d: %s - %s\n", count, temp->kor, temp->eng);
    temp = temp->next;
    count++;
  }
}


void searchWord(char *word)
{
    Line *temp = head;
    int lineNumber = 1;
    int found = 0;

    while (temp != NULL)
    {
        if (strstr(temp->kor, word) != NULL || strstr(temp->eng, word) != NULL)
        {
            printf("Found '%s' at line %d\n", word, lineNumber);
            found = 1;
        }

        temp = temp->next;
        lineNumber++;
    }

    if (!found)
    {
        printf("Word not found!\n");
    }
}

void saveToFile(char *fileName)
{
    FILE *file = fopen(fileName, "w");
    Line *temp = head;

    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    while (temp != NULL)
    {
        fprintf(file, "%s %s\n", temp->kor, temp->eng);
        temp = temp->next;
    }

    fclose(file);
}

void loadFromFile(char *fileName)
{
    FILE *file = fopen(fileName, "r");
    if(file == NULL) {
        printf("Could not open file %s\n", fileName);
        return;
    }
    char line[2048];

    if (file == NULL)
    {
        printf("Could not open file!\n");
        return;
    }

    while (fgets(line, sizeof(line), file))
    {
        char *kor = strtok(line, " ");
        char *eng = strtok(NULL, " ");

        kor[strlen(kor) - 1] = '\0';
        insertLine(size() + 1, kor, eng); // 수정
    }

    fclose(file);
}

int main()
{

    setlocale(LC_ALL, "ko_KR.UTF-8");

    char command;
    char inputBuffer[1024];

    int lineNum;
    char kor[1024], eng[1024];

    while (1)
    {

        printf("[메뉴 선택] i-입력(행번호는 1부터), d-삭제, r-변경, p-출력, l-파일읽기, s-저장, f-단어찾기, q-종료=> ");
        scanf(" %c", &command);

        switch (command)
        {

        case 'i':
            printf("행 번호: ");
            scanf("%d", &lineNum);
            getchar();
            printf("한글: ");
            fgets(kor, sizeof(kor), stdin);
            printf("영어: ");
            fgets(eng, sizeof(eng), stdin);
            insertLine(lineNum, kor, eng);
            break;

        case 'd':
            printf("Enter line number to delete: ");
            scanf("%d", &lineNum);
            deleteLine(lineNum);
            break;

        case 'u':
            printf("Enter line number to update: ");
            scanf("%d", &lineNum);
            printf("Enter new text: ");
            scanf(" %[^\n]s", inputBuffer);
            updateLine(lineNum, inputBuffer, "");
            break;

        case 'p':
            printLines();
            break;

        case 's':
            printf("Enter word to search: ");
            scanf(" %[^\n]s", inputBuffer);
            searchWord(inputBuffer);
            break;

        case 'q':
            saveToFile("output.txt");
            return 0;

        case 'r':
            shuffleLines();  
            break;

        case 'l':
            loadFromFile("data.txt");
            break;

        default:
            printf("Invalid command.\n");
        }
    }

    saveToFile("output.txt"); // 종료 부분에 파일 저장 기능 추가
    return 0;
}