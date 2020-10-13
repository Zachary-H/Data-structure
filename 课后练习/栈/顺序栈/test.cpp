#include "stack.h"
#include <stdio.h>

int main()
{
	Stack st;
	StackInit(&st);
	Push(&st, 10);

	InfixToSuffix(&st);

	return 0;
}