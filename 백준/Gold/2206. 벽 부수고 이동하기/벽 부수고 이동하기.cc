#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, M, dist = -1;
	cin >> N >> M;

	vector<vector<int>> map(N, vector<int>(M));
	vector<vector<vector<bool>>> visited(N, vector<vector<bool>>(M, vector<bool>(2)));
	int dy[] = { 0, 1, 0, -1 };
	int dx[] = { 1, 0, -1, 0 };

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		for (int j = 0; j < M; j++)
		{
			map[i][j] = (str[j] == '1');
		}
	}

	queue<vector<int>> q;
	q.push({ 0, 0, 1, 0 }); // y, x, dist, breakedCnt
	visited[0][0][0] = true;

	while (!q.empty())
	{
		vector<int> values = q.front(); q.pop();
		int y = values[0], x = values[1], d = values[2], broken = values[3];

		if (y == N - 1 && x == M - 1)
		{
			dist = d;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = dy[i] + y;
			int nx = dx[i] + x;

			if (ny >= 0 && ny < N && nx >= 0 && nx < M)
			{
				// 벽이 없는 경우, 현재 벽 부순 여부를 유지하면서 방문 처리
				if (map[ny][nx] == 0 && !visited[ny][nx][broken])
				{
					q.push({ ny, nx, d + 1, broken });
					visited[ny][nx][broken] = true;
				}
				// 벽이 있는 경우, 한 번도 부수지 않은 상태에서만 부술 수 있음
				else if (map[ny][nx] == 1 && broken == 0 && !visited[ny][nx][1])
				{
					q.push({ ny, nx, d + 1, 1 });
					visited[ny][nx][1] = true;
				}
			}
		}
	}

	cout << dist;
	return 0;
}