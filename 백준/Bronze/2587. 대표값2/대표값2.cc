#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int sum = 0;
	int arr[5];

	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}

	sort(arr, arr + sizeof(arr) / sizeof(arr[0]));

	cout << sum / 5 << "\n" << arr[2];
}