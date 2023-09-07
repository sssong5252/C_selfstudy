#include<stdio.h>
int main() {
    int target,low,high,mid;
    int data[10] = { 2,3,5,7,8,9,11,13,15,20 };
    
    scanf("%d", &target);
    low = 0; //search대상범위의 첫번째값 
    high = 9; //search대상범위의 마지막값
    
    while (low <= high) {
        mid = (low + high) / 2;
        if (target == data[mid]) { //탐색 성공
            printf("%d는 %d번째 index에 있습니다.", target, mid);
            return 0;
        }
        else if (target < data[mid]) { // 탐색 범위 재조정 low ~ mid-1
            high = mid - 1;
        }
        else if (target > data[mid]) { // 탐색 범위 재조정 mid+1 ~ high
            low = mid + 1;
        }
    }
    
    printf("%d는 존재하지 않습니다.", target);
    return 0;
}