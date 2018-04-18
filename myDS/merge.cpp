#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "List.h"
using std::cin;
using std::cout;


List Read(); /* 细节在此不表 */
void Print(List L); /* 细节在此不表；空链表将输出NULL */
void test(List L1)
{
	List p = (List)malloc(sizeof(struct Node));
	p->Data = 0;
	List s = L1;
	L1 = L1->Next;
	free(s);
	p->Next = L1;

	free(L1);
}
List Merge(List L1, List L2);

List Read()
{
	int K;
	cin >> K;
	List L = (List)malloc(sizeof(struct Node));
	L->Next = NULL;
	List p = L;
	int num;
	int flag = 1;
	while (K--)
	{
		cin >> num;
		List s = (List)malloc(sizeof(struct Node));
		s->Data = num;
		s->Next = NULL;
		p->Next = s;
		p = p->Next;
	}
	return L;
}
void Print(List L)
{
	while (L->Next!= NULL)
	{
		cout << L->Data << " ";
		L = L->Next;
	}
	cout << L->Data << "\n";
}
List Merge(List L1, List L2)
{
	List L3 = (List)malloc(sizeof(struct Node));
	L3->Next = NULL;
	if (L1->Next == NULL&&L2->Next == NULL)
		return L3;
	else if (L1->Next == NULL)
	{
		L3->Next = L2->Next;
		L2->Next = NULL;
		return L3;
	}
	else if(L2->Next == NULL){
		L3->Next = L1->Next;
		L1->Next = NULL;
		return L3;
	}

	List p1 = L1->Next;
	List p2 = L2->Next;
	List cur = L3;

	while (p1->Next != NULL && p2->Next != NULL)
	{
		if (p1->Data < p2->Data)
		{
			L1->Next = p1->Next;
			cur->Next = p1;
			p1->Next = NULL;
			cur = cur->Next;
			p1 = L1->Next;
		}
		else
		{
			L2->Next = p2->Next;
			cur->Next = p2;
			p2->Next = NULL;
			cur = cur->Next;
			p2 = L2->Next;
		}
	}
	if (p1->Next == NULL&&p2->Next != NULL)
	{
		while (p2->Data < p1->Data)
		{
			L2->Next = p2->Next;
			cur->Next = p2;
			p2->Next = NULL;
			cur = cur->Next;
			p2 = L2->Next;
		}
		cur->Next = p1;
		L1->Next = NULL;
		cur = cur->Next;
		cur->Next = p2;
		L2->Next = NULL;
	}
	else if (p1->Next != NULL && p2->Next == NULL)
	{
		while (p1->Data < p2->Data)
		{
			L1->Next = p1->Next;
			cur->Next = p1;
			p1->Next = NULL;
			cur = cur->Next;
			p1 = L1->Next;
		}
		cur->Next = p2;
		L2->Next = NULL;
		cur = cur->Next;
		cur->Next = p1;
		L1->Next = NULL;
	}
	return L3;
}