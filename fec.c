#include <stdio.h>

int main() {
	int num, i, fst;
	printf("num: ");
	scanf("%d", &num);
	fst = 1;

	for(i = 1; i <= num; i++) {
		fst *= i;
	}

	printf("%d",fst);
	return 0;
}
