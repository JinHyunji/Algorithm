#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, M, B;
	cin >> N >> M >> B;
	vector<vector<int>> site(N, vector<int>(M, -1));

	int minH = 256, maxH = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> site[i][j];
			if (site[i][j] < minH) minH = site[i][j];
			if (site[i][j] > maxH) maxH = site[i][j];
		}
	}

	// 땅의 높이가 모두 같다면 0, 현재 높이 출력
	if (minH == maxH)
	{
		cout << "0" << " " << minH;
		return 0;
	}

	int answer[2]; answer[0] = INT32_MAX; answer[1] = 0;
	for (int h = minH; h <= maxH; h++)
	{
		int sumB = B;
		int sumTime = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (site[i][j] < h)
				{
					sumB -= (h - site[i][j]);
					sumTime += (h - site[i][j]);
				}
				else if (site[i][j] > h)
				{
					sumB += (site[i][j] - h);
					sumTime += (site[i][j] - h) * 2;
				}
			}
		}

		if (sumB < 0) continue;
		
		if (sumTime < answer[0])
		{
			answer[0] = sumTime;
			answer[1] = h;
		}
		else if (sumTime == answer[0])
			answer[1] = h > answer[1] ? h : answer[1];
	}

	cout << answer[0] << " " << answer[1];
	return 0;
}