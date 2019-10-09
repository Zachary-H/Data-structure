#include "HeadList.h"
#include <stdio.h>

int main()
{
	Node head;  
	InitSingleList(&head);

	for (int i = 0; i < 10; ++i)
	{
		InsertSingleTail(&head, i + 30);
	}

	ShowSingleList(&head);

	InsertSinglePos(&head, 100, 4);

	ShowSingleList(&head);

	DeleteSinglePos(&head, 6);

	ShowSingleList(&head);

	FindRecipKey(&head, 2);

	FindRecipKey(&head, 0);

	FindRecipKey(&head, 10);

	FindRecipKey(&head, 11);

	printf("%d\n", (FindNodeOfkTail(&head, 2))->data);
	//printf("%d\n", (FindNodeOfkTail(&head, 0))->data);
	printf("%d\n", (FindNodeOfkTail(&head, 10))->data);
	//printf("%d\n", (FindNodeOfkTail(&head, 11))->data);

	DeletePosInO1(FindNodeOfkTail(&head, 2));

	ShowSingleList(&head);

}