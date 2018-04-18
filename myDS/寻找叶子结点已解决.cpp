#include <iostream>
using namespace std;

#define Null -1
#define MaxSize 10
#define Tree char
struct TreeNode
{
	char Left;
	char Right;
}T[MaxSize];
int first = 1;
Tree Build(struct TreeNode* T)
{
	int N;
	cin >> N;
	int Root = Null;
	if (N)
	{
		char cl, cr;
		int i = 0;
		char check[MaxSize] = { 0 };
		for ( i = 0; i < N; i++)
		{
			cin >> cl >> cr;
			if (cl != '-')
			{
				T[i].Left = cl - '0';
				check[T[i].Left] = 1;
			}
			else T[i].Left = Null;

			if (cr != '-')
			{
				T[i].Right = cr - '0';
				check[T[i].Right] = 1;
			}
			else T[i].Right = Null;
		}
		for (i = 0; i < N; i++)
			if (!check[i])break;
		Root = i;
	}
	return Root;
}
void PrintLeaf(Tree r)
{
	char q[MaxSize + 1];
	for (size_t i = 0; i < MaxSize+1; i++)
		q[i] = -1;
	
	int head = 0, rear = 0;
	q[rear] = r;
	rear++;
	while (q[head]!=-1)
	{
		char cl = T[q[head]].Left;
		char cr = T[q[head]].Right;
		if(cl!=Null)
			q[rear++] = cl;
		if(cr!=Null)
			q[rear++] = cr;
		if ( cl == Null&& cr ==Null )
		{
			if (first)
			{
				cout << (int)q[head];
				first = 0;
			}
			else
				cout << " " << (int)q[head];
		}
		q[head] = -1;
		head++;
	}
}
int main()
{
	Tree R = Build(T);
	PrintLeaf(R);
	system("pause");
	return 0;
}