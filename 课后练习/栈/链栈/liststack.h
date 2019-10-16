#pragma once

typedef int ElemType;

typedef struct _Node
{
	ElemType data;
	struct _Node *next;
}Node;

typedef struct _ListStack
{
	Node head;
	int count;
}ListStack, *ptrListStack;

bool ListStackInit(ptrListStack lst);

bool IsListStackEmpty(ptrListStack lst);

bool ListStackPush(ptrListStack lst, ElemType val);

bool ListStackPop(ptrListStack lst, ElemType* val);

bool ListStackTop(ptrListStack lst, ElemType* val);

bool ListStackDestroy(ptrListStack lst);