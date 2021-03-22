#include <stdio.h>
int main()
{
	int n,m;
	scanf("%d %d", &n, &m);
	int arr[n],trr[m];
	for(int j = 0; j < n; j++)
	{
		scanf("%d", &arr[j]);
	}
	for(int j = 0; j < m; j++)
	{
		scanf("%d", &trr[j]);
	}
	for(int j = 0; j < m; j++)
	{
		printf("%d\n",arr[trr[j]-1]);
	}
	return 0;
}
