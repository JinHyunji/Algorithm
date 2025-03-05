#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	vector<int> dp(N);

	dp[0] = 1;
	dp[1] = 3;
	for (int i = 2; i < N; i++)
	{
		dp[i] = (dp[i - 1] + (dp[i - 2] * 2)) % 10007;
	}

	cout << dp[N - 1];
	
	return 0;
}