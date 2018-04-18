#include <cstdio>
#include <cstdlib>

int reverse(int x) {
	const int maxInt = 2147483647;
	int isNeg = 0;
	int num;
	if (x<0)
	{
		isNeg = 1;
		num = 0 - x;
	}
	else
		num = x;
	num = -2147483648;
	int res = 0;
	int bit = 0;
	while (num != 0)
	{
		int t = num % 10;
		num = num / 10;
		res = res * 10 + t;
		bit++;
		if (bit == 9)
		{
			if (res > maxInt / 10)
				return 0;
			else if (res == maxInt / 10 && (num % 10) > 7)
				return 0;
		}
	}
	if (isNeg)
		return 0 - res;
	else
		return res;
}
int main()
{
	int t = reverse(23);
	printf("%d", t);
	system("pause");
	return 0;
}