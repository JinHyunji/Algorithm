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

	vector<int> arr(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	if (N == 2)
	{
		cout << arr[0] << " " << arr[1] << endl;
		return 0;
	}

	int start = 0;
	int end = N - 1;
	int absMin = 2000000000;
	vector<int> result(2);

	while (start < end)
	{
		int sum = arr[start] + arr[end];
		int absSum = abs(sum);

		if (absSum < absMin)
		{
			result[0] = arr[start];
			result[1] = arr[end];
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
			cout << arr[start] << " " << arr[end] << endl;
			return 0;
		}
	}
	
	//sort(result.begin(), result.end());

	cout << result[0] << " " << result[1];
	return 0;
}