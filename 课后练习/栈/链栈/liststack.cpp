#include "liststack.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <assert.h>

bool ListStackInit(ptrListStack lst)
{
	assert(lst != NULL);
	if (lst == NULL)
	{
		printf("%s:%d error!", __FILE__, __LINE__);
		return false;
	}

	lst->head.next = NULL;
	lst->count = 0;
	return true;
}

bool ListStackPush(ptrListStack lst, ElemType val)
{
	assert(lst != NULL);
	if (lst == NULL)
	{
		printf("%s:%d error!", __FILE__, __LINE__);
		return false;
	}

	Node* new_node = (Node*)malloc(sizeof(Node));
	assert(new_node != NULL);

	new_node->data = val;
	new_node->next = lst->head.next;
	lst->head.next = new_node;
	lst->count++;
	
	return true;
}

bool IsListStackEmpty(ptrListStack lst)
{
	assert(lst != NULL);
	if (lst == NULL)
	{
		printf("%s:%d error!", __FILE__, __LINE__);
		return false;
	}

	if (lst->count == 0)
	{
		return true;
	}

	return false;
}

bool ListStackPop(ptrListStack lst, ElemType* val)
{
	assert(lst != NULL);
	if (lst == NULL)
	{
		printf("%s:%d error!", __FILE__, __LINE__);
		return false;
	}

	if (IsListStackEmpty(lst))
	{
		return false;
	}

	Node* p;
	p = lst->head.next;
	*val = lst->head.data;
	lst->head.next = lst->head.next->next;

	free(p);

	return true;
}

bool ListStackTop(ptrListStack lst, ElemType* val)
{
	assert(lst != NULL);
	if (lst == NULL)
	{
		printf("%s:%d error!", __FILE__, __LINE__);
		return false;
	}

	if (IsListStackEmpty(lst))
	{
		return false;
	}

	*val = lst->head.data;

	return true;
}

bool ListStackDestroy(ptrListStack lst)
{
	assert(lst != NULL);
	if (lst == NULL)
	{
		printf("%s:%d error!", __FILE__, __LINE__);
		return false;
	}

	while (!IsListStackEmpty(lst))
	{
		ListStackPop(lst, NULL);
	}

	return true;
}
