#include <iostream>
#include <vector>
using namespace std;


int main()
{
	// 입력
	int N, K;
	long long mod = 1000000000;
	cin >> N >> K;
	vector<vector<long long>> dp(K + 1, vector<long long>(N + 1));

	for (int i = 0; i <= N; i++) dp[1][i] = 1;
	for (int i = 1; i <= K; i++) dp[i][0] = 1;

	for (int k = 2; k <= K; k++)
	{
		for (int n = 1; n <= N; n++)
		{
			dp[k][n] = (dp[k][n - 1] + dp[k - 1][n]) % mod;
		}
	}

	// 출력
	cout << dp[K][N] << endl;
}