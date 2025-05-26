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

#define X first
#define Y second

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int T, M, N, K;
int map[50][50];
bool visited[50][50];

void BFS(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[y][x] = true;

	while (!q.empty())
	{
		auto [x, y] = q.front(); q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
			if (map[ny][nx] == 0 || visited[ny][nx]) continue;

			q.push({ nx, ny });
			visited[ny][nx] = true;
		}
	}

	return;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--)
	{
		cin >> M >> N >> K;

		std::fill(&visited[0][0], &visited[0][0] + 50 * 50, false);
		std::fill(&map[0][0], &map[0][0] + 50 * 50, 0);

		for (int i = 0; i < K; i++)
		{
			int x, y;
			cin >> x >> y;
			map[y][x] = 1;
		}

		int answer = 0;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				if (map[y][x] == 1 && !visited[y][x])
				{
					answer++;
					BFS(x, y);
				}
			}
		}

		cout << answer << "\n";
	}

	return 0;
}