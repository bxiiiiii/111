#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(void *a, void *b, int n)
{
    void *temp = malloc(n);
	memcpy(temp, a, n);
	memcpy(a, b, n);
	memcpy(b, temp, n);
}

int main()
{
    auto a, b;
    scanf("%d %d", &a, &b);
    printf("a = %d b = %d\n", a, b);
    swap(&a, &b, sizeof(a));
    printf("a = %d b = %d\n", a, b);
    return 0;
}