#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int minV = 100;
	int sum = 0;

	for (int i = 0; i < 7; i++)
	{
		int num;
		cin >> num;
		if (num % 2 != 0)
		{
			sum += num;
			if (num < minV)
				minV = num;
		}
	}

	if (sum == 0)
		cout << -1;
	else
	{
		cout << sum << "\n" << minV;
	}
}