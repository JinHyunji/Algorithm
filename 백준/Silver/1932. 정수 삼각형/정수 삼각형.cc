#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	vector<vector<int>> triangle(N, vector<int>(N));
	vector<vector<int>> dp(N, vector<int>(N));

	for (int i = 0; i < N; i++)
		for (int j = 0; j <= i; j++)
			cin >> triangle[i][j];

	dp[0][0] = triangle[0][0];
	for (int i = 1; i < N; i++)
	{
		dp[i][0] = dp[i - 1][0] + triangle[i][0];
		dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
	}

	for (int i = 2; i < N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			dp[i][j] = max(dp[i - 1][j - 1] + triangle[i][j], dp[i - 1][j] + triangle[i][j]);		
		}
	}

	int result = 0;
	for (int i = 0; i < N; i++)
	{
		result = max(result, dp[N - 1][i]);
	}

	cout << result;
}