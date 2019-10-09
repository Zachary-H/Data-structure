#pragma once

typedef int ElemType;

typedef bool(*Compare)(ElemType a, ElemType b);

typedef struct _Node
{
	ElemType data;       //结点的数据域
	struct _Node *next;  //结点的指针域
}Node,*SingleList;

void InitSingleList(SingleList slist);

void InsertSinglePos(SingleList slist, ElemType val, int pos);

void InsertSingleHead(SingleList slist, ElemType val);

void InsertSingleTail(SingleList slist, ElemType val);

void DeleteSinglePos(SingleList slist, int pos);

void DeleteSingleHead(SingleList slist);

void DeleteSingleTail(SingleList slist);

void ShowSingleList(SingleList slist);

void FindRecipKey(SingleList slist, int k);

SingleList FindNodeOfkTail(SingleList slist, int k);

void DeletePosInO1(SingleList p);

int IsCross(SingleList a, SingleList b);

