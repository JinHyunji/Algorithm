#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int T, K, N;
	string output;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> K >> N;
		vector<vector<int>> dp(K + 1, vector<int>(N + 1, 1));

		for (int i = 2; i <= N; i++)
		{
			dp[0][i] = i;
		}

		for (int i = 1; i <= K; i++)
		{
			for (int j = 2; j <= N; j++)
			{
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
			}
		}

		output += to_string(dp[K][N]) + "\n";
	}

	cout << output;
}