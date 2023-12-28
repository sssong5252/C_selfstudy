#include <stdio.h>

int main()
{
	int X, N, a, b, hap = 0;

	scanf("%d\n%d", &X, &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		
		hap += (a * b);
	}

	if (X == hap) {
		printf("Yes\n");
	}
	else
		printf("No\n");

	return 0;
}