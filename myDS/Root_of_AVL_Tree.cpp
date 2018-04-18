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

typedef int ElementType;
typedef struct AVLNode* AVLTree;
struct AVLNode
{
	ElementType val;
	int depth = 0;
	AVLTree left;
	AVLTree right;
};
void leftRotate(AVLTree AVLT)
{

}
void rightRotate(AVLTree AVLT)
{

}
AVLTree BalanceInsert(AVLTree AVLT, ElementType X)
{
	if (AVLT == NULL)
	{
		AVLT = (AVLTree)malloc(sizeof(struct AVLNode));
		AVLT->left = AVLT->right = NULL;
		AVLT->depth = 0;
		AVLT->val = X;
	}
	else
	{
		//insert element
		if (X < AVLT->val)
		{
			AVLT->left = BalanceInsert(AVLT->left, X);
			AVLT->depth++;
		}
		else if (X > AVLT->val)
		{
			AVLT->right = BalanceInsert(AVLT->right, X);
			AVLT->depth--;
		}
		
		//check all depth, if any node has a depth of 2 or -2, Rotate.
		if (AVLT->depth == 2)
		{
			cout << "depth is 2\n";
		}
		else if (AVLT->depth == -2)
		{
			cout << "depth is -2\n";
		}
	}
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