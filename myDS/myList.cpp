#include "list.h"

int Length(List* list)
{
	int i = 1;
	while (list->next != NULL)
	{
		list = list->next;
		i++;
	}
	return i;
}
List* Insert(int X, int K, List* list)
{
	if (K == 1)//往头部插入
	{
		List* temp = (List*)malloc(sizeof(List));
		temp->element = X;
		temp->next = list;
		return temp;
	}
	if (K == Length(list) + 1)
	{
		List* p = FindKth(K - 1, list);
		List* temp = (List*)malloc(sizeof(List));
		temp->element = X;
		temp->next = NULL;
		p->next = temp;
		return list;
	}
	else
	{
		List* p = FindKth(K - 1, list);
		List* temp = (List*)malloc(sizeof(List));
		temp->element = X;
		temp->next = p->next;
		p->next = temp;
		return list;
	}
}
List* Delete(int K, List* list)
{
	List* temp = (List*)malloc(sizeof(List));
	if (K == 1)
	{
		temp = list;
		list = list->next;
		free(temp);
		return list;
	}
	List* p = FindKth(K - 1, list);
	if (p == NULL)
		return NULL;
	else
	{
		temp = p->next;
		p->next = temp->next;
		free(temp);
		return list;
	}
}
List* FindKth(int K, List* list)
{
	int i = 1;
	while (list->next != NULL && i < K)
	{
		list = list->next;
		i++;
	}
	if (i == K)
		return list;
	else
		return NULL;
}
int Find(int X, List* list)
{
	int i = 1;
	while (list->element != X && list->next != NULL)
	{
		list = list->next;
		i++;
	}
	if (list->next == NULL)
		return -1;
	else
		return i;
}
List* Input()
{
	int num;
	int i = 2;
	List* list = (List*)malloc(sizeof(List));
	scanf_s("%d", &num);
	list->element = num;
	list->next = NULL;
	while (scanf_s("%d", &num) == 1 && num!=-1)
	{
		list = Insert(num, i, list);
		i++;
	}
	return list;
}
void PrintList(List* list)
{
	while (list->next != NULL)
	{
		printf("%d ", list->element);
		list = list->next;
	}
	printf("%d\n", list->element);
}
int main()
{
	List* list = (List*)malloc(sizeof(List));
	list->next = NULL;
	list = Input();
	int t = Find(4, list);
	printf("%d\n", t);
	//PrintList(list);
	system("pause");
	return 0;
}


