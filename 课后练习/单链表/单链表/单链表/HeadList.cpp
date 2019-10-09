#include "HeadList.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <malloc.h>

////////////////////////内置函数////////////////////////
static int GetListLength(SingleList slist)
{
	int count = 0;
	SingleList p = slist->next;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}

	return count;
}

static SingleList FindPriorOfPos(SingleList slist, int pos)
{
	SingleList p = slist;

	while (pos)
	{
		p = p->next;
		pos--;
	}

	return p;
}

static SingleList ApplyNode(ElemType val, SingleList ptr)
{
	SingleList Newnode = (SingleList)malloc(sizeof(Node));
	assert(Newnode != NULL);
	if (Newnode == NULL)
	{
		printf("%s:%d error\n", __FILE__, __LINE__);
		return NULL;
	}

	Newnode->data = val;
	Newnode->next = ptr;

	return Newnode;
}

///////////////////////////////////////////////////////

void InitSingleList(SingleList slist)
{
	assert(slist != NULL);
	if (slist == NULL)
	{
		printf("%s:%d funaction InitSingleList: 请给一个有效的头结点\n", __FILE__, __LINE__);
		return;
	}

	slist->next = NULL;
}

void InsertSinglePos(SingleList slist, ElemType val, int pos)
{
	assert(slist != NULL);
	if (slist == NULL)
	{
		printf("%s:%d funaction InsertSinglePos: 请给我一个有效的头结点\n", __FILE__, __LINE__);
		return;
	}

	// 1、判断pos位置是否合法, 如果位置不合法，则直接尾插
	if (pos < 0 || pos > GetListLength(slist))
	{
		InsertSinglePos(slist, val, GetListLength(slist));
	}

	// 2、找到要插入的pos位置的前一个结点
	SingleList prior = FindPriorOfPos(slist, pos);

	// 3、申请一个新的结点， 并且将val，以及next域都设置好
	SingleList Newnode = ApplyNode(val, prior->next);
	if (Newnode == NULL)
	{
		return;
	}

	// 4、将插入的pos位置前一个结点的next设置为新结点的地址
	prior->next = Newnode;

}

void InsertSingleHead(SingleList slist, ElemType val)
{
	InsertSinglePos(slist, val, 0);
}

void InsertSingleTail(SingleList slist, ElemType val)
{
	InsertSinglePos(slist, val, GetListLength(slist));
}

void DeleteSinglePos(SingleList slist, int pos)
{
	assert(slist != NULL);
	if (slist == NULL)
	{
		printf("%s:%d funaction DeleteSinglePos: 请给我一个有效的头结点\n", __FILE__, __LINE__);
		return;
	}

	// 1、判断删除的位置是否合法
	if (pos < 0 || pos > GetListLength(slist) - 1)
	{
		return;
	}

	// 2、找pos位置的前一个结点
	SingleList prior = FindPriorOfPos(slist, pos);

	// 3、先将prior的next结点记录下来
	SingleList p = prior->next;

	// 4、将prior的next设置为p的next
	prior->next = p->next;

	// 5、释放p结点
	free(p);
}

void DeleteSingleHead(SingleList slist)
{
	DeleteSinglePos(slist, 0);
}

void DeleteSingleTail(SingleList slist)
{
	DeleteSinglePos(slist, GetListLength(slist) - 1);
}

SingleList FindNode(SingleList slist, ElemType val, Compare cp)
{
	assert(slist != NULL);
	if (slist == NULL)
	{
		printf("%s:%d funaction FindNode: 请给一个有效的头结点\n", __FILE__, __LINE__);
		return NULL;
	}

	SingleList p = slist->next;

	while (p != NULL)
	{
		if (cp(p->data, val))
		{
			return p;
		}

		p = p->next;
	}

	return NULL;
}

void ClearSingleList(SingleList slist)
{
	assert(slist != NULL);
	if (slist == NULL)
	{
		printf("%s:%d funaction ClearSingleList: 请给一个有效的头结点\n", __FILE__, __LINE__);
		return;
	}

	while (slist->next != NULL)
	{
		DeleteSingleHead(slist);
	}
}

void DestroySingleList(SingleList slist)
{
	ClearSingleList(slist);
}

void FindRecipKey(SingleList slist, int k)
{
	int count = GetListLength(slist);
	int tmp = count - k + 1;

	if (tmp <= 0 || k == 0)
	{
		printf("k值不正确\n");
		return;
	}

	SingleList p = slist;
	while(tmp)
	{
		p = p->next;
		tmp--;
	}

	printf("%d\n", p->data);
}

void DeletePosInO1(SingleList p)
{
	if (p == NULL || p->next == NULL)
	{
		return;
	}

	SingleList tmp = p->next;

	p->data = p->next->data;
	p->next = p->next->next;

	free(tmp);
}

int IsCross(SingleList a, SingleList b)
{
	SingleList p1 = a;
	SingleList p2 = b;

	while (p1 != NULL && p1->next != NULL)
	{
		p1 = p1->next;
	}

	while (p2 != NULL && p2->next != NULL)
	{
		p2 = p2->next;
	}

	return p1 == p2;
}

void ShowSingleList(SingleList slist)
{
	assert(slist != NULL);
	if (slist == NULL)
	{
		printf("%s:%d funaction ShowSingleList: 请给一个有效的头结点\n", __FILE__, __LINE__);
		return;
	}

	SingleList p = slist->next;
	while (p != NULL)
	{
		printf("%d  ", p->data);
		p = p->next;
	}

	printf("\n");
}

SingleList FindNodeOfkTail(SingleList slist, int k)
{
	assert(slist != NULL);
	if (slist == NULL && k <= 0)
	{
		printf("%s:%d funaction FindNodeOfkTail error\n", __FILE__, __LINE__);
		return NULL;
	}

	SingleList p = slist, q = slist;

	while (k && q != NULL)
	{
		q = q->next;
		k--;
	}

	if (q == NULL)
	{
		return NULL;
	}

	while (q != NULL)
	{
		p = p->next;
		q = q->next;
	}

	return p;
}