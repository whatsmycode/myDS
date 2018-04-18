#include <cstdio>
#include <cstdlib>
#include "List.h"

//返回表长
int Length(List PtrL)
{
	List p = PtrL;
	int j = 0;
	while (p)
	{
		p = p->Next;
		j++;
	}
	return j;
}
//返回指向第K个元素的指针
List FindKth(int K, List PtrL)
{
	List p = PtrL;
	int i = 1;
	while (p != NULL && i < K)
	{
		p = p->Next;
		i++;
	}
	if (i == K)
		return p;
	else
		return NULL;
}
//返回值为K的节点的指针
List Find(ElementType X, List PtrL)
{
	List p = PtrL;
	while (p != NULL && p->Data != X)
		p = p->Next;
	return p;
}
//insert new element
List Insert(ElementType X, int i, List PtrL)
{
	List p, s;
	if (i == 1)
	{
		s = (List)malloc(sizeof(struct Node));
		s->Data = X;
		s->Next = PtrL;
		return s;
	}
	p = FindKth(i - 1, PtrL);
	if (p == NULL)
		return NULL;
	else
	{
		s = (List)malloc(sizeof(struct Node));
		s->Data = X;
		s->Next = p->Next;
		p->Next = s;
		return PtrL;
	}
}
//delete an element
List Delete(int i, List PtrL)
{
	List p, s;
	if (i == 1)
	{
		s = PtrL;
		if (PtrL != NULL)
			PtrL = PtrL->Next;
		else
			return NULL;
		free(s);
		return PtrL;
	}
	p = FindKth(i - 1, PtrL);
	if (p == NULL)
		return NULL;
	else if (p->Next == NULL)
		return NULL;
	else{
		s = p->Next;
		p->Next = s->Next;
		free(s);
		return PtrL;
	}
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
	else if (L2->Next == NULL){
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

List Reverse(List L)
{
	List p = (List)malloc(sizeof(struct Node));
	p->Data = L->Data;
	p->Next == NULL;
	if (L->Next != NULL)
		L = L->Next;
	else
		return p;
	while (L->Next != NULL)
	{
		List tmp = (List)malloc(sizeof(struct Node);
		tmp->Data = L->Data;
		tmp->Next = p->Next;
		p->Next = tmp;
		L = L->Next;
	}
	List tmp = (List)malloc(sizeof(struct Node);
	tmp->Data = L->Data;
	tmp->Next = p->Next;
	p->Next = tmp;
	return p;
}

List Read()
{
	
	return List();
}
