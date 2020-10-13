#pragma once

typedef char ElemType;

typedef struct _stack
{
	ElemType *data;
	int stack_size;
	int top;
}Stack, *ptrStack;

bool StackInit(ptrStack st, int size = 10);

bool IsFull(ptrStack st);

bool IsEmpty(ptrStack st);

bool Push(ptrStack st, ElemType val);

bool Pop(ptrStack st, ElemType* val);

bool Top(ptrStack st, ElemType* val);

bool Destroy(ptrStack st);

int In(char e);//判断读入字符是否为运算符

char Compare(char a, char b);//比较运算符的优先级

bool InfixToSuffix(ptrStack lst);



