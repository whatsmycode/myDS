#pragma once
#include <stdio.h>
#include <stdlib.h>

struct List {
	int element;
	List* next;
};
int Length(List* list);
List* Insert(int X, int K, List* list);
List* Delete(int K, List* list);
List* FindKth(int K, List* list);
int Find(int X, List* list);