#include <iostream>
using namespace std;

int N, M, cnt = 0, maxW = 0;
int map[500][500];
bool visited[500][500];
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
int area; // 현재 그림의 크기

void DFS(int x, int y)
{
	visited[y][x] = true;
	area++; // 현재 그림의 크기 증가

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		if (visited[ny][nx] || map[ny][nx] == 0) continue;

		DFS(nx, ny);
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
				area = 0; // 새 그림 시작 시 크기 초기화
				DFS(x, y);
				cnt++;
				maxW = max(maxW, area); // 가장 큰 그림 크기 업데이트
			}
		}
	}

	cout << cnt << endl << maxW;
	return 0;
}