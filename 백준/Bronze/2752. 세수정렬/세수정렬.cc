#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int nums[3];
	for (int i = 0; i < 3; i++)
	{
		cin >> nums[i];
	}

	std::sort(nums, nums + sizeof(nums) / sizeof(nums[0]));

	for (int n : nums)
		cout << n << " ";
}