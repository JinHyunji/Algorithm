#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
using namespace std;

int N, M, K;
int map[1000][1000];
bool visited[1000][1000][10];
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;

	for (int y = 0; y < N; y++)
	{
		string str;
		cin >> str;
		for (int x = 0; x < M; x++)
		{
			map[y][x] = str[x] - '0';
		}
	}

	queue<tuple<int, int, int, int>> q; 
	q.push({ 0, 0, 1, K }); // y, x, dist, k
	visited[0][0][K] = true;

	while (!q.empty())
	{
		auto [y, x, dist, k] = q.front();
		q.pop();

		if (y == N - 1 && x == M - 1)
		{
			cout << dist;
			return 0;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

			if (k > 0)
			{
				if (map[ny][nx] == 1 && !visited[ny][nx][k-1])
				{
					q.push({ ny, nx, dist + 1, k - 1 });
					visited[ny][nx][k - 1] = true;
				}
				else if (map[ny][nx] == 0 && !visited[ny][nx][k])
				{
					q.push({ ny, nx, dist + 1, k });
					visited[ny][nx][k] = true;
				}
			}
			else
			{
				if (map[ny][nx] == 1 || visited[ny][nx][k]) continue;
				q.push({ ny, nx, dist + 1, k });
				visited[ny][nx][k] = true;
			}
		}
	}

	cout << -1;
	return 0;
}