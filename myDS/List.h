
typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
	ElementType Data; /* �洢������� */
	PtrToNode   Next; /* ָ����һ������ָ�� */
};
typedef PtrToNode List; /* ���嵥�������� */

int Length(List PtrL);
List FindKth(int K, List PtrL);
List Find(ElementType X, List PtrL);
List Insert(ElementType X, int i, List PtrL);
List Delete(int i, List PtrL);
List Merge(List L1, List L2);
List Reverse(List L);
List Read();