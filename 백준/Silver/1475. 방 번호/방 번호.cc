#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int set[10];

int main()
{
	string N;
	cin >> N;

	for (int i = 0; i < N.size(); i++)
		set[N[i] - '0']++;

	int max = 0;
	int maxIdx = -1;
	for (int i = 0; i < 10; i++)
	{
		if (set[i] > max)
		{
			max = set[i];
			maxIdx = i;
		}
		else if (set[i] == max)
		{
			if (i != 6 && i != 9)
			{
				maxIdx = i;
			}
		}
	}

	if (maxIdx == 6 || maxIdx == 9)
	{
		int sum = set[6] + set[9];
		int ans = (sum % 2 == 0) ? sum / 2 : sum / 2 + 1;
		cout << ans;
	}
	else
	{
		cout << max;
	}
}