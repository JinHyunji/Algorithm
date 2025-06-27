#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int answer;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
string map[5];
bool perm[25];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 5; i++)
		cin >> map[i];

	// 1. 25명 중 7명 뽑기 (조합 사용)
	fill(perm + 7, perm + 25, true);
	do
	{
		queue<pair<int, int>> q;
		bool isPicked[5][5] = { false }, visited[5][5] = { false };
		int cntS = 0, adj = 0;
		for (int i = 0; i < 25; i++)
		{
			if (!perm[i])
			{
				int x = i / 5, y = i % 5;
				isPicked[x][y] = true;
				if (q.empty())
				{
					q.push({ x, y });
					visited[x][y] = true;
				}
			}
		}

		while (!q.empty())
		{
			auto [x, y] = q.front(); q.pop();
			adj++;
			if (map[x][y] == 'S') cntS++;

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5 || visited[nx][ny] || !isPicked[nx][ny]) continue;

				q.push({ nx, ny });
				visited[nx][ny] = true;
			}
		}

		answer += (adj >= 7 && cntS >= 4);
	} while (next_permutation(perm, perm + 25));

	cout << answer;
}