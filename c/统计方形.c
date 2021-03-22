#include <stdio.h>
int main()
{
	int a, b, sum = 0;
	scanf("%d %d", &a, &b);
	for (int i = 1; i < (a < b ? a : b); i++)
	{
		for(int j = i; j <= a; j++)
		{
			for(int t = i; t <= b; t++)
			{
				sum++;
			}
		}
	}
	printf("%d", sum);
	return 0;
}
