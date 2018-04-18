#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;

struct TNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

void PreorderTraversal(BinTree BT);
void InorderTraversal(BinTree BT);

BinTree Insert(BinTree BST, ElementType X);
BinTree Delete(BinTree BST, ElementType X);
Position Find(BinTree BST, ElementType X);
Position FindMin(BinTree BST);
Position FindMax(BinTree BST);
BinTree InsertLeft(BinTree BST,ElementType X)
{
	if (BST == NULL)
	{
		BST = (BinTree)malloc(sizeof(struct TNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	}
	else if (BST->Left == NULL)
	{
		BinTree tmp = (BinTree)malloc(sizeof(struct TNode));
		tmp->Data = X;
		tmp->Left = tmp->Right = NULL;
		BST->Left = tmp;
	}
	return BST;
}
BinTree InsertRight(BinTree BST, ElementType X)
{
	if (BST == NULL)
	{
		BST = (BinTree)malloc(sizeof(struct TNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	}
	else if (BST->Right == NULL)
	{
		BinTree tmp = (BinTree)malloc(sizeof(struct TNode));
		tmp->Data = X;
		tmp->Left = tmp->Right = NULL;
		BST->Right = tmp;
	}
	return BST;
}
bool isValidBST(BinTree BST)
{
	if (BST == NULL)
		return true;
	if (BST->Left != NULL && BST->Right != NULL)
	{
		if (FindMax(BST->Left)->Data >= BST->Data || FindMin(BST->Right)->Data <= BST->Data)
			return false;
		else
			return isValidBST(BST->Left) && isValidBST(BST->Right);
	}
	else if (BST->Left != NULL && BST->Right == NULL)
	{
		if (FindMax(BST->Left)->Data >= BST->Data)
			return false;
		else
			return isValidBST(BST->Left);
	}
	else if (BST->Left == NULL && BST->Right != NULL)
	{
		if (FindMin(BST->Right)->Data <= BST->Data)
			return false;
		else
			return isValidBST(BST->Right);
	}
	else
		return true;
}
int main()
{
	BinTree BST = NULL;
	BST = InsertLeft(BST, 10);
	BST = InsertLeft(BST, 5);
	BST = InsertRight(BST, 15);
	BST->Right = InsertLeft(BST->Right, 6);
	BST->Right = InsertRight(BST->Right, 20);

	
	if (isValidBST(BST))
		printf("true\n");
	else
		printf("false\n");

	system("pause");
	return 0;
}

void PreorderTraversal(BinTree BT)
{
	if (BT != NULL)
	{
		printf("%d", BT->Data);
		PreorderTraversal(BT->Left);
		PreorderTraversal(BT->Right);
	}
}

void InorderTraversal(BinTree BT)
{
	if (BT != NULL)
	{
		InorderTraversal(BT->Left);
		printf("%d", BT->Data);
		InorderTraversal(BT->Right);
	}
}

BinTree Insert(BinTree BST, ElementType X)
{
	if (BST == NULL)
	{
		BST = (BinTree)malloc(sizeof(struct TNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	}
	else
	{
		if (X < BST->Data)
			Insert(BST->Left, X);
		else
			Insert(BST->Right, X);
	}
	return BST;
}

BinTree Delete(BinTree BST, ElementType X)
{
	return BinTree();
}

Position Find(BinTree BST, ElementType X)
{
	if (BST == NULL)
		return NULL;
	else
	{
		if (X < BST->Data)
			Find(BST->Left, X);
		else if (X > BST->Data)
			Find(BST->Right, X);
		else
			return BST;
	}
}

Position FindMin(BinTree BST)
{
	if (BST == NULL)
		return NULL;
	else
	{
		BinTree cur = BST;
		while (cur->Left)
			cur = cur->Left;
		return cur;
	}
}

Position FindMax(BinTree BST)
{
	if (BST == NULL)
		return NULL;
	else
	{
		BinTree cur = BST;
		while (cur->Right)
			cur = cur->Right;
		return cur;
	}
}
