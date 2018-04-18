
typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
	ElementType Data; /* 存储结点数据 */
	PtrToNode   Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

int Length(List PtrL);
List FindKth(int K, List PtrL);
List Find(ElementType X, List PtrL);
List Insert(ElementType X, int i, List PtrL);
List Delete(int i, List PtrL);
List Merge(List L1, List L2);
List Reverse(List L);
List Read();