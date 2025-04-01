#include <iostream>
using namespace std;

int N, M, cnt = 0, maxW = 0;
int map[500][500];
bool visited[500][500];
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

void DFS(int x, int y, int& w)
{
	visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		if (visited[ny][nx] || map[ny][nx] == 0) continue;

		w++;
		DFS(nx, ny, w);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			cin >> map[y][x];

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (!visited[y][x] && map[y][x] == 1)
			{
				int widthCnt = 1;
				DFS(x, y, widthCnt);
				if (widthCnt > maxW) maxW = widthCnt;
				cnt++;
			}
		}
	}

	cout << cnt << endl << maxW;
	return 0;
}