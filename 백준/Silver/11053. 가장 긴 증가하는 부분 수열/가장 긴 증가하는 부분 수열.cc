#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	// 입력
	int N, result = 0;
	cin >> N;

	vector<int> sequence(N); // 수열
	for (int& s : sequence)
		cin >> s;

	// 로직
	vector<int> lengths(N); // 최대 길이
	for (int i = 0; i < N; i++)
	{
		int maxLen = 0;

		for (int j = 0; j < i; j++)
		{
			if (sequence[i] > sequence[j])
			{
				maxLen = max(maxLen, lengths[j]);
			}
		}

		lengths[i] = maxLen + 1;
	}

	// 출력
	for (int& len : lengths)
		result = max(len, result);

	cout << result << endl;
	return 0;
}