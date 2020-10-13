#include "stack.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <assert.h>

bool IsFull(ptrStack st)
{
	if (st->top == st->stack_size)
	{
		printf("The stack is full\n");
		return true;
	}

	return false;
}

bool IsEmpty(ptrStack st)
{
	if (st->top == 0)
	{
		printf("The stack is empty\n");
		return true;
	}

	return false;
}

bool StackInit(ptrStack st, int size)
{
	assert(st != NULL);
	if (st == NULL)
	{
		printf("%s:%d error!\n", __FILE__, __LINE__);
		return false;
	}

	st->data = (ElemType*)malloc(sizeof(ElemType) * size);
	assert(st->data != NULL);
	if (st->data == NULL)
	{
		printf("malloc fail!\n");
		return false;
	}

	st->stack_size = size;
	st->top = 0;

	return true;
}

bool Push(ptrStack st, ElemType val)
{
	assert(st != NULL);
	if (st == NULL)
	{
		printf("%s:%d error!\n", __FILE__, __LINE__);
		return false;
	}

	if (IsFull(st))
	{
		return false;
	}

	st->data[st->top] = val;
	st->top++;

	return true;
}

bool Pop(ptrStack st, ElemType* val)
{
	assert(st != NULL);
	if (st == NULL)
	{
		printf("%s:%d error!", __FILE__, __LINE__);
		return false;
	}

	if (IsEmpty(st))
	{
		return false;
	}

	*val = st->data[st->top - 1];
	st->top--;

	return true;
}

bool Top(ptrStack st, ElemType* val)
{
	assert(st != NULL);
	if (st == NULL)
	{
		printf("%s:%d error!", __FILE__, __LINE__);
		return false;
	}

	if (IsEmpty(st))
	{
		return false;
	}

	*val = st->data[st->top - 1];

	return true;
}

bool Destroy(ptrStack st)
{
	assert(st != NULL);
	if (st == NULL)
	{
		printf("%s:%d error!", __FILE__, __LINE__);
		return false;
	}

	free(st->data);

	st->stack_size = 0;
	st->top = 0;

	return true;
}

int In(char e)
{
	if (e == '+' || e == '-' || e == '*' || e == '/' || e == '(' || e == ')' || e == '#')
		return 1;//ÊÇ 
	else
		return 0; //²»ÊÇ 
}
char Compare(char a, char b)
{
	char f;
	if (a == '+' || a == '-')
	{
		if (b == '+' || b == '-')
			f = '>';
		else if (b == '*' || b == '/')
			f = '<';
	}
	else if (a == '*' || a == '/')
	{
		if (b == '+' || b == '-' || b == '*' || b == '/')
			f = '>';
	}
	else if (a == '#')
	{
		if (b == '+' || b == '-' || b == '*' || b == '/' || b == '(')
			f = '<';
		else if (b == '#')
			f = '=';
	}
	return f;
}

bool InfixToSuffix(ptrStack st)
{
	char ch;
	char c;

	ch = getchar();

	while (1)
	{
		if (!In(ch))
		{
			printf("%c", ch);
		}

		else if (ch == '#')
		{
			while (st->top != 0)
			{
				Pop(st, &c);
				printf("%c", c);
			}
		}

		else if (ch == ')')
		{ 
			Pop(st, &c);
			while (c != '(')
			{
				printf("%c", c);
				Pop(st, &c);
			}
		}

		else if (ch == '(')
		{
			Push(st, ch);
		}
			
		else if (st->top != st->stack_size)
		{
			Push(st, ch);
		}
			
		else 
		{          
			char t = Compare(Top(st, &c), ch);
			while (t == '>')
			{
				Pop(st, &c);
				printf("%c", c);
				t = Compare(Top(st, &c), ch);
			}
			Push(st, ch);
		}
		ch = getchar();
	}

	return true;
}