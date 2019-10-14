#include "stack.h"
#include <stdio.h>

int main()
{
	Stack st;
	StackInit(&st);
	Push(&st, 10);

	return 0;
}