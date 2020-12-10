#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	int i = 0;
	char* arr[100];
	char str[10002];
	do
	{
		fgets(str, 10002, stdin);
		arr[i] = (char*)malloc(strlen(str+1)*sizeof(char));
		strcpy(arr[i], str);
	} while (strcmp(str, "."));
	for (; i > 0; i--)
	{
		printf("%s",arr[i]);
	}

	return 0;
}
