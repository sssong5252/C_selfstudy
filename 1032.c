#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 50

int main() {
	int n;
	char first_str[MAX_LENGTH];
	char next_str[MAX_LENGTH];

	scanf("%d", &n);
	scanf("%s", first_str);

	for (int i = 0; i < n - 1; i++) {
		scanf("%s", next_str);

		for(int j = 0; j < strlen(first_str); j++) {
			if (first_str[j] != '?' && first_str[j] != next_str[j]) {
				first_str[j] = '?';
			}
		}
	}

	printf("%s\n", first_str);

	return 0;
}