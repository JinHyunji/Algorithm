#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	vector<vector<int>> triangle(N, vector<int>(N));
	vector<vector<int>> dp(N, vector<int>(N));

	// 입력 받기
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= i; j++)
			cin >> triangle[i][j];

	// DP 초기값 설정 (꼭대기)
	dp[0][0] = triangle[0][0];

	// Bottom-Up Dp 계산
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0) // 왼쪽 끝
				dp[i][j] = dp[i - 1][j] + triangle[i][j];
			else if (j == i) // 오른쪽 끝
				dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
			else // 중간 값
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
		}
	}

	// 마지막 행에서 최대값 찾기
	int result = *max_element(dp[N - 1].begin(), dp[N - 1].end());
	cout << result;

	return 0;
}