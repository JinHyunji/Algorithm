#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M;
	std::cin >> N >> M;

	std::vector<int> lectures(N);
	int max = 0;
	int min = 0;

	for (int i = 0; i < N; i++) {
		std::cin >> lectures[i];
		min = std::max(min, lectures[i]);
		max += lectures[i];
	}

	int result = 0;

	while (min <= max)
	{
		int mid = (min + max) / 2;
		int sum = 0;
		int cnt = 1;

		for (int i = 0;i < N; i++) {
			if (lectures[i] + sum > mid)
			{
				cnt++;
				sum = lectures[i];
			}
			else
			{
				sum += lectures[i];
			}
		}

		if (cnt <= M)
		{
			result = mid;
			max = mid - 1;
		} 
		else
		{
			min = mid + 1;
		}
	}

	std::cout << result;

	return 0;
}