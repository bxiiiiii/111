#include<stdio.h>

void swap(int* a, int m, int n);
void adjust(int* a, int s, int e);
void sort(int* a, int len);

int main()
{
	int num[] = {0,5,2,7,8,6,5,9,4,2,};
	int len = sizeof(num) / sizeof(num[0]);
	sort(num, len);
	for (int i = 1; i < len; i++)
	{
		printf("%d ", num[i]);
	}
	return 0;
}

void swap(int* a, int m, int n)
{
	int tem = a[m];
	a[m] = a[n];
	a[n] = tem;
}

void adjust(int* a, int s, int e)
{
	int tem = a[s];
	for (int j = 2 * s; j <=e; j *= 2)
	{
		if(j<e && a[j] < a[j+1]) j++;
		if(tem >= a[j]) break;
		a[s] = a[j];
		s=j;
	}
	a[s] = tem;
}

void sort(int* a, int len)
{
	for(int i = (len-1)/2; i > 0; i--)
	{
		adjust(a, i, len);
	}
	for(int j = len-1; j > 0; j--)
	{
		swap(a, 1, j);
		adjust(a, 1, j-1);
	}
}
