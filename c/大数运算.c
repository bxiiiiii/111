#include<stdio.h>
#include<string.h>

int add(char* a1, char* a2, int* a3);

int main()
{
	char a1[] = "123456789123";
	char a2[] = "345678912345";
	int a3[1000] = {0};
	int len = add(a1,a2,a3);
	for (int i = len - 1; i >= 0; i--)
	{
		printf("%d", a3[i]);
	}
	return 0;
}

int add(char* a1, char* a2, int* a3)
{
	int i , j;
	int n2[1000] = {0};
	int len1 = strlen(a1);
	int len2 = strlen(a2);
	int len = len1 > len2 ? len1 : len2;
	for (i = len1-1, j = 0; i >= 0; i--, j++)
	{
		a3[j] = a1[i] - '0';
	}
	for (i = len2-1, j = 0; i >= 0; i--, j++)
	{
		n2[j] = a2[i] - '0';
	}
	for (i = 0; i <= len; i++)
	{
		a3[i] += n2[i];
		if(a3[i]>9)
		{
			a3[i] -= 10;
			a3[i+1]++;
		}
	}
	if(a3[len] != 0)
		len++;
	return len;
}
