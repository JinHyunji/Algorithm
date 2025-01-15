#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


static int lowerBound(int, const std::vector<int>&);
static int upperBound(int, const std::vector<int>&);

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M;
	std::cin >> N >> M;
	std::vector<int> dots(N);

	for (int i = 0; i < N; i++)
	{
		std::cin >> dots[i];
	}

	std::sort(dots.begin(), dots.end());
	std::string output;

	for (int i = 0; i < M; i++)
	{
		int start, end;
		std::cin >> start >> end;

		output += std::to_string((upperBound(end, dots) - lowerBound(start, dots) + 1)) + "\n";
	}

	std::cout << output;
}

static int lowerBound(int start, const std::vector<int>& dots)
{
	int min = 0;
	int max = dots.size();

	while (min < max)
	{
		int mid = (min + max) / 2;

		if (dots[mid] < start)
		{
			min = mid + 1;
		}
		else {
			max = mid;
		}
	}

	return min;
}

static int upperBound(int end, const std::vector<int>& dots)
{
	int min = 0;
	int max = dots.size();

	while (min < max)
	{
		int mid = (min + max) / 2;

		if (dots[mid] <= end)
		{
			min = mid + 1;
		}
		else {
			max = mid;
		}
	}

	return min - 1;
}