#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MAX 100

typedef struct write {
    double time;
    int sums;
    char num[MAX];
} write;

typedef write e;
typedef struct Link {
    struct Link* link;
    e data;
} Node;

Node* head = NULL;
int count[MAX] = { 0 };
int sum = 0;

void insert_next(Node* prev, Node* new_node);

int fibIter(int n) {
    int i = 1;
    count[n] += i;
    sum++;
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return (fibIter(n - 1) + fibIter(n - 2));
}

Node* get_entry(int pos) {
    int i = 0;
    Node* p = head;
    for (i = 0; i < pos; i++, p = p->link) {
        if (p == NULL)
            return NULL;
    }
    return p;
}

void insert(int pos, e val) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = val;
    Node* prev;
    if (pos == 0) {
        new_node->link = head;
        head = new_node;
    }
    else {
        prev = get_entry(pos - 1);
        if (prev != NULL) {
            insert_next(prev, new_node);
        }
        else {
            free(new_node);
        }
    }
}

void insert_next(Node* prev, Node* new_node) {
    if (new_node != NULL) {
        new_node->link = prev->link;
        prev->link = new_node;
    }
}

void display(FILE* fp) {
    int i = 0;
    Node* p;
    for (p = head; p != NULL; p = p->link, i++) {
        fprintf(stderr, "%3d", i);
        fprintf(fp, "%d번으로 함수를 호출하였고, 시간은 %.3lf초 걸렸고, 총 함수의 호출 횟수는 %d번입니다.\n", atoi(p->data.num), p->data.time, p->data.sums);
    }
}

int main() {
    int i;
    int n;
    clock_t start, finish;
    double avg;
    FILE* fp;
    while (1) {
        printf("구하고 싶은 피보나치 수열을 입력하시오 (ex:10,2,6)(-1누르면 종료)(값을 저장하고 싶으면 s를 눌러 주세요!): ");
        char input[10];
        scanf("%s", input);
        if (input[0] == 's') {
            fp = fopen("fibo.txt", "w");
            if (fp != NULL) {
                display(fp);
                fclose(fp);
            }
            continue;
        }
        n = atoi(input);
        if (n == -1) {
            printf("프로그램을 종료합니다. \n");
            return 0;
        }
        start = clock();
        fibIter(n);
        finish = clock();
        avg = (double)(finish - start) / CLOCKS_PER_SEC;
        printf("피보나치 수열은 %.3lf초 걸렸습니다 \n", avg);
        printf("fib[%d]은 총 %d번 호출되었습니다 \n", n, sum);
        e new_entry;
        new_entry.time = avg;
        new_entry.sums = sum;
        strcpy(new_entry.num, input);
        insert(0, new_entry);
        for (i = n; i >= 0; i--)
            printf("fib[%d] = %d 번 \n", i, count[i]);
        sum = 0;
    }
}
