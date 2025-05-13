#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool freq[1000001];

int main()
{
	int N, X, answer = 0;
	cin >> N;

	vector<int> arr(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	cin >> X;

	for (int i = 0; i < N; i++)
	{
		int diff = X - arr[i];

		if (diff <= 0 || diff > 1000000) continue;

		if (freq[diff])
		{
			answer++;
		}
		else
		{
			freq[arr[i]] = true;
		}
		
	}

	cout << answer;
	return 0;
}