#include <stdio.h>
#include <string.h>
int main()
{
	char string[80];
	
	strcpy(string, "Hello world from");
	strcat(string, 80, "strcpy");

	printf("string=%s\n", string);
}
