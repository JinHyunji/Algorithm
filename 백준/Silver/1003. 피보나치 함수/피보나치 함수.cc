#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int T, N;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> N;

		int dp[2][41] = { 0 };

		dp[0][0] = dp[1][1] = 1;

		for (int i = 2; i <= N; i++)
		{
			dp[0][i] = dp[0][i - 1] + dp[0][i - 2];
			dp[1][i] = dp[1][i - 1] + dp[1][i - 2];
		}

		cout << dp[0][N] << " " << dp[1][N] << endl;
	}
}