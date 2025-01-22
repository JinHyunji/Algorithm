#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<long long> arr(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	if (N == 3)
	{
		cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
		return 0;
	}

	long long absMin = 3000000000;
	vector<long long> result(3);

	for (int i = 0; i < N - 2; i++)
	{
		int start = i + 1;
		int end = N - 1;

		while (start < end)
		{
			long long sum = arr[i] + arr[start] + arr[end];
			long long absSum = abs(sum);

			if (absSum < absMin)
			{
				result[0] = arr[i];
				result[1] = arr[start];
				result[2] = arr[end];
				absMin = absSum;
			}

			if (sum < 0)
			{
				start += 1;
			}
			else if (sum > 0)
			{
				end -= 1;
			}
			else
			{
				cout << arr[i] << " " << arr[start] << " " << arr[end];
				return 0;
			}
		}
	}

	cout << result[0] << " " << result[1] << " " << result[2];
	return 0;
}