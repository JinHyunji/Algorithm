#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include <vector>
#include <sstream>
#include <stack>
#include <queue>
#include <tuple>
using namespace std;

int N, M;
int map[1000][1000];
queue<tuple<int, int, int>> q;
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> M >> N;

	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < M; y++)
		{
			cin >> map[x][y];

			if (map[x][y] == 1)
			{
				q.push({ x, y, 0 });
			}
		}
	}

	int day = 0;
	while (!q.empty())
	{
		auto [x, y, dist] = q.front(); q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (map[nx][ny] != 0) continue;

			q.push({ nx, ny, dist + 1 });
			map[nx][ny] = 1;
		}

		if (q.empty())
			day = dist;
	}

	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < M; y++)
		{
			if (map[x][y] == 0)
			{
				cout << -1;
				return 0;
			}
		}
	}

	cout << day;
}