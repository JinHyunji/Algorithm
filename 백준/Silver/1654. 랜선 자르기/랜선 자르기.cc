#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int K, N;
	std::cin >> K >> N;
	std::vector<long> vec(K);
	long max = 0;
	
	for (int i = 0; i < K; i++)
	{
		std::cin >> vec[i];
		max = std::max(max, vec[i]);
	}

	long min = 1;
	long result = 0;

	while (min <= max)
	{
		long mid = (min + max) / 2;
		int cnt = 0;

		for (int v : vec)
		{
			cnt += (v / mid);
		}

		if (cnt >= N)
		{
			result = mid;
			min = mid + 1;
		}
		else
		{
			max = mid - 1;
		}
	}

	std::cout << result;
}