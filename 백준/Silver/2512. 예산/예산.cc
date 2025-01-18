#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int N, M, max;
	cin >> N;

	max = 0;
	vector<int> budget(N);
	for (int i = 0; i < N; i++) {
		cin >> budget[i];
		max = std::max(max, budget[i]);
	}

	cin >> M;

	int min = 1;
	int result = 0;

	while (min <= max)
	{
		int mid = (min + max) / 2;
		int sum = 0;

		for (int i = 0;i < N; i++)
		{
			if (budget[i] <= mid)
			{
				sum += budget[i];
			}
			else
			{
				sum += mid;
			}
		}

		if (sum <= M)
		{
			result = mid;
			min = mid + 1;
		}
		else
		{
			max = mid - 1;
		}
	}
	
	cout << result;
}