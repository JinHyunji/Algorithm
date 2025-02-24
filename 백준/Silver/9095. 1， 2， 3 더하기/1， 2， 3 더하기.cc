#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int T, N;
	string output;

	// 입력
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> N;

		vector<int> dp(N + 1);

		dp[1] = 1; dp[2] = 2; dp[3] = 4;
		for (int i = 4; i <= N; i++)
		{
			dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
		}

		output += to_string(dp[N]) + "\n";
	}

	// 출력
	cout << output;
}