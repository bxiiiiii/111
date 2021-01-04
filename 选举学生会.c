#include<stdio.h>

void sort(int* a, int len);
void swap(int* a, int b, int c);
void adjust(int* a, int s, int e);

int main()
{
	int a,b;
	scanf("%d %d", &a, &b);
	int num[b+1];
	num[0] = 0;
	for(int i = 1; i < b+1; i++)
	{
		scanf("%d", &num[i]);
	}
	sort(num, b+1);
	for (int i = 1; i < b+1; i++)
	{
		printf("%d ", num[i]);
	}
	return 0;
}

void sort(int* a, int len)
{
	int j;
	for (j = (len-1) / 2; j > 0; j--)
	{
		adjust(a, j, len - 1);
	}
	for (j = len - 1; j > 0; j--)
	{
		swap(a, 1, j);
		adjust(a, 1, j - 1);
	}
}

void swap(int* a, int b, int c)
{
	int tem = a[b];
	a[b] = a[c];
	a[c] = tem;
}

void adjust(int* a, int s, int e)
{
	int tem = a[s];
	for (int j = 2 * s; j <= e; j *= 2)
	{
		if (a[j] < a[j + 1] && j < e) j++;
		if (tem >= a[j]) break;
		a[s] = a[j];
		s = j;
	}
	a[s] = tem;
}

