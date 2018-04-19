/*
An AVL tree is a self-balancing binary search tree. In an AVL tree, the heights of the two child subtrees of any node differ by at most one; if at any time they differ by more than one, rebalancing is done to restore this property. Figures 1-4 illustrate the rotation rules.
Now given a sequence of insertions, you are supposed to tell the root of the resulting AVL tree.
Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (¡Ü20) which is the total number of keys to be inserted. Then N distinct integer keys are given in the next line. All the numbers in a line are separated by a space.
Output Specification:
For each test case, print the root of the resulting AVL tree in one line.
*/
#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

typedef int ElementType;
typedef struct AVLNode* AVLTree;
struct AVLNode
{
	ElementType val;
	int height = 0;
	AVLTree left;
	AVLTree right;
};
int Height(AVLTree AVLT)
{
	if (AVLT == NULL)
		return -1;
	else if (AVLT->left == NULL && AVLT->right == NULL)
		return 0;
	else if (AVLT->left != NULL && AVLT->right == NULL)
		return AVLT->left->height + 1;
	else if (AVLT->left == NULL && AVLT->right != NULL)
		return AVLT->right->height + 1;
	else
		return (AVLT->left->height > AVLT->right->height ? AVLT->left->height : AVLT->right->height) + 1;
}
AVLTree clockwiseRotate(AVLTree AVLT)
{
	AVLTree tmp = AVLT;
	AVLT = tmp->left;
	tmp->left = AVLT->right;
	AVLT->right = tmp;

	tmp->height = Height(tmp->left) > Height(tmp->right) ? Height(tmp->left) : Height(tmp->right) + 1;
	AVLT->height = Height(AVLT->left) > Height(AVLT->right) ? Height(AVLT->left) : Height(AVLT->right) + 1;
	return AVLT;
}
AVLTree anticlockwiseRotate(AVLTree AVLT)
{
	AVLTree tmp = AVLT;
	AVLT = tmp->right;
	tmp->right = AVLT->left;
	AVLT->left = tmp;

	tmp->height = Height(tmp->left) > Height(tmp->right) ? Height(tmp->left) : Height(tmp->right) + 1;
	AVLT->height = Height(AVLT->left) > Height(AVLT->right) ? Height(AVLT->left) : Height(AVLT->right) + 1;
	return AVLT;
}
AVLTree doubleRotateClockwise(AVLTree AVLT)
{
	AVLT->left = anticlockwiseRotate(AVLT->left);
	return clockwiseRotate(AVLT);
}
AVLTree doubleRotateAntiClockwise(AVLTree AVLT)
{
	AVLT->right = clockwiseRotate(AVLT->right);
	return anticlockwiseRotate(AVLT);
}
AVLTree BalanceInsert(AVLTree AVLT, ElementType X)
{
	if (AVLT == NULL)
	{
		AVLT = (AVLTree)malloc(sizeof(struct AVLNode));
		AVLT->left = AVLT->right = NULL;
		AVLT->height = 0;
		AVLT->val = X;
	}
	else
	{
		//insert element
		if (X < AVLT->val)
		{
			AVLT->left = BalanceInsert(AVLT->left, X);
			if (Height(AVLT->left) - Height(AVLT->right) == 2)
			{
				if (X < AVLT->left->val)
					AVLT = clockwiseRotate(AVLT);
				else
					AVLT = doubleRotateClockwise(AVLT);
			}
		}
		else if (X > AVLT->val)
		{
			AVLT->right = BalanceInsert(AVLT->right, X);
			if (Height(AVLT->right) - Height(AVLT->left) == 2)
			{
				if (X > AVLT->right->val)
					AVLT = anticlockwiseRotate(AVLT);
				else
					AVLT = doubleRotateAntiClockwise(AVLT);
			}
		}	
	}
	AVLT->height = Height(AVLT);
	return AVLT;
}
int main()
{
	int N;
	cin >> N;
	AVLTree AVLT = NULL;

	int data;
	while (N--)
	{
		cin >> data;
		AVLT = BalanceInsert(AVLT, data);
	}
	cout << AVLT->val;
	return 0;
}