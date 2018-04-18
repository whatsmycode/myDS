#include <iostream>
#include <cstdlib>
using std::cin;
using std::cout;

typedef struct PolyNode* Polynomial;
struct PolyNode {
	int coef;
	int expon;
	Polynomial link;
};
void Attach(int c, int e, Polynomial *pRear)
{
	Polynomial P;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->coef = c;
	P->expon = e;
	P->link = NULL;
	(*pRear)->link = P;
	*pRear = P;
}
Polynomial ReadOnly()
{
	Polynomial P, Rear, t;
	int c, e, N;
	cin >> N;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->link = NULL;
	Rear = P;
	while (N--)
	{
		//scanf("%d %d", &c, &e);
		cin >> c >> e;
		Attach(c, e, &Rear);
	}
	t = P; P = P->link; free(t);
	return P;
}
void PrintOnly(Polynomial P)
{
	int flag = 0;
	if (!P) { /*printf("0 0\n");*/ cout << "0 0\n"; return; }
	while (P)
	{
			if (!flag)
				flag = 1;
			else
				cout << " ";//printf(" ");
			cout << P->coef << " " << P->expon;
			//printf("%d %d", P->coef, P->expon); 
		
		P = P->link;
	}
	cout << "\n";
}
//输入的多项式按指数降序排列，不带头结点
Polynomial Add(Polynomial Poly1, Polynomial Poly2)
{
	Polynomial p1 = Poly1;
	Polynomial p2 = Poly2;
	Polynomial p3 = (Polynomial)malloc(sizeof(struct PolyNode));
	p3->coef = 0;
	int first = 1;
	
	Polynomial cur = p3;
	Polynomial previous = cur;
	//获取两个多项式中指数较大的项，若两个指数相等，则返回系数之和
	//保存到tmp中
	while (p1 != NULL && p2 != NULL)
	{
		Polynomial tmp = (Polynomial)malloc(sizeof(struct PolyNode));
		if (p1->expon > p2->expon)
		{
			tmp->coef = p1->coef;
			tmp->expon = p1->expon;
			tmp->link = NULL;
			p1 = p1->link;
		}
		else if (p1->expon == p2->expon)
		{
			tmp->coef = p1->coef + p2->coef;
			tmp->expon = p1->expon;
			tmp->link = NULL;
			p1 = p1->link;
			p2 = p2->link;
		}
		else
		{
			tmp->coef = p2->coef;
			tmp->expon = p2->expon;
			tmp->link = NULL;
			p2 = p2->link;
		}

		if (tmp->coef == 0)
			continue;

		if (first)
		{
			p3->coef = tmp->coef;
			p3->expon = tmp->expon;
			p3->link = NULL;
			first = 0;
		}
		else
		{
			if (cur->expon == tmp->expon)
				cur->coef += tmp->coef;
			else
			{
				if (cur->coef == 0)
				{
					cur->coef = tmp->coef;
					cur->expon = tmp->expon;
					cur->link = NULL;
				}
				else
				{
					cur->link = tmp;
					cur = cur->link;
				}
			}
		}
	}
	//一个多项式已走完，剩下的一个多项式若指数相同，则系数相加，否则接上
	if (p1 == NULL)
	{
		while (p2 != NULL)
		{
			if (p2->expon == cur->expon)
				cur->coef += p2->coef;
			else
			{
				Polynomial t = (Polynomial)malloc(sizeof(struct PolyNode));
				t->coef = p2->coef;
				t->expon = p2->expon; 
				t->link = NULL;
				if (first)
				{
					p3 = t;
					first = 0;
				}
				else
				{
					if (cur->coef == 0)
					{
						cur->coef = t->coef;
						cur->expon = t->expon;
						cur->link = NULL;
					}
					else
					{
						cur->link = t;
						cur = cur->link;
					}
				}
			}
			p2 = p2->link;
		}
	}
	else
	{
		while (p1 != NULL)
		{
			if (p1->expon == cur->expon)			
				cur->coef += p1->coef;		
			else
			{
				Polynomial t = (Polynomial)malloc(sizeof(struct PolyNode));
				t->coef = p1->coef;
				t->expon = p1->expon;
				t->link = NULL;

				if (first)
				{
					p3 = t;
					first = 0;
				}
				else
				{
					if (cur->coef == 0)
					{
						cur->coef = t->coef;
						cur->expon = t->expon;
						cur->link = NULL;
					}
					else
					{
						cur->link = t;
						cur = cur->link;
					}
				}
			}	
			p1 = p1->link;
		}
	}
	if (p3->coef == 0)
		return NULL;
	else
		return p3;
}
Polynomial Multi(Polynomial Poly1, Polynomial Poly2)
{
	Polynomial p1 = Poly1;
	Polynomial p2 = Poly2;
	Polynomial p3 = (Polynomial)malloc(sizeof(struct PolyNode));
	p3->coef = 0;
	p3->expon = 0;
	p3->link = NULL;
	if (!p1 || !p2)	return NULL;

	int firstTime = 1;
	for (p1 = Poly1; p1 != NULL; p1 = p1->link)
	{
		for (p2 = Poly2; p2!=NULL; p2 = p2->link)
		{
			Polynomial tmp = (Polynomial)malloc(sizeof(struct PolyNode));
			tmp->coef = p1->coef * p2->coef;
			tmp->expon = p1->expon + p2->expon;
			tmp->link = NULL;
			if (firstTime == 1)
			{
				p3 = tmp;
				firstTime = 0;
			}
			else
				p3 = Add(p3, tmp);
		}
	}
	return p3;
}

int main()
{
	Polynomial poly1 = ReadOnly();
 	Polynomial poly2 = ReadOnly();
	Polynomial addPoly = Add(poly1, poly2);
	Polynomial multyPoly = Multi(poly1, poly2);
	PrintOnly(multyPoly);
	PrintOnly(addPoly);
	system("pause");
	return 0;
}
