#include <stdio.h>
void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	int x = 10, y = 15;
	swap(&x, &y);
	printf("x:%d\ny:%d\n", x, y);
	return 0;
}
