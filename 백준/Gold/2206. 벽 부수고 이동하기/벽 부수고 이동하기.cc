#include <iostream>
#include <queue>
#include <tuple>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

const static int MAX = 1000;
int N, M;
int map[MAX][MAX];
bool visited[MAX][MAX][2]; // 벽을 안 부순 경우와 부순 경우의 방문 배열

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	for (int x = 0; x < N; x++)
	{
		string input;
		cin >> input;

		for (int y = 0; y < M; y++)
		{
			map[x][y] = input[y] - '0';
		}
	}

	queue<tuple<int, int, int, bool>> q;
	q.push({ 0, 0, 1, false }); // x, y, dist, broken
	visited[0][0][0] = true; // 벽을 안 부순 경우의 방문 처리

	while (!q.empty())
	{
		auto [x, y, dist, broken] = q.front(); q.pop();

		if (x == N - 1 && y == M - 1)
		{
			cout << dist;
			return 0;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

			if (map[nx][ny] == 0 && !visited[nx][ny][broken]) // 벽이 아니고 방문한 적이 없으면 방문
			{
				visited[nx][ny][broken] = true;
				q.push({ nx, ny, dist + 1, broken });
			}
			else if (map[nx][ny] == 1 && broken == false && !visited[nx][ny][1]) // 벽이지만 뚫은적 없고 방문한 적 없으면 방문
			{
				visited[nx][ny][1] = true;
				q.push({ nx, ny, dist + 1, true });
			}
		}
	}

	cout << -1;
	return 0;
}