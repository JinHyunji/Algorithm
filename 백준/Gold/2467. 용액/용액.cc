#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> liquid(N);

	for (int i = 0; i < N; i++)
	{
		cin >> liquid[i];
	}

	int start = 0;
	int end = N - 1;
	int min = 2000000000;
	int result[]{ 0,0 };

	while (start < end)
	{
		int sum = liquid[start] + liquid[end];
		int absSum = abs(sum);

		if (absSum < min)
		{
			result[0] = liquid[start];
			result[1] = liquid[end];
			min = absSum;
		}

		if (sum < 0)
		{
			start += 1;
		}
		else if (sum > 0)
		{
			end -= 1;
		}
		else {
			break;
		}
	}

	if (result[0] < result[1])
	{
		cout << result[0] << " " << result[1];
	}
	else {
		cout << result[1] << " " << result[0];
	}
}