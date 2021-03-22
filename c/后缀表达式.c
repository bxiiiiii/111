#include <stdio.h>
#include <stdlib.h>

typedef struct sta
{
	char a[1000];
	int top;
}staa;

staa* init(staa* s);
void push(staa* s, int n);
void pop(staa *s);

int main()
{
	staa s;
}

staa* init(staa* s)
{
	staa* s = (staa*)malloc(sizeof(staa));
	top = 0;
	return s;
}

void push(staa* s, int n)
{
	
}

