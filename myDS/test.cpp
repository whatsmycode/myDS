#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	vector<int> nums;
	while (1)
	{
		cin >> n;
		if (n != -1)
			nums.push_back(n);
		else
			break;
	}
	vector<int>::iterator it = nums.begin();
	int size = nums.size();
	for (int i  = 0; i+1<size;)
	{
		if (nums[i] == nums[i + 1])
		{
			nums.erase(it + i + 1);
			size--;
		}
		else
			i++;
	}
	cout << nums.size() << endl;
	for (size_t i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	
	return 0;
}