#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> arr(21);
	for (int i = 1; i < 21; i++)
	{
		arr[i] = i;
	}

	for (int i = 0; i < 10; i++)
	{
		int a, b;
		cin >> a >> b;

		for (int idx = 0; idx < (b - a + 1) / 2; idx++)
		{
			int start = a + idx;
			int end = b - idx;
			int temp = arr[start];
			arr[start] = arr[end];
			arr[end] = temp;
		}
	}

	for (int i = 1; i < 21; i++)
		cout << arr[i] << " ";
}