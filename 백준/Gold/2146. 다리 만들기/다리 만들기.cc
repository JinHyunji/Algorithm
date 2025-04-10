#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
int map[100][100] = { 0, };
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
vector<pair<int, int>> borders[10002];

void Sorting(int y, int x, int label)
{
	map[y][x] = label;

	bool isBorder = false;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
		if (map[ny][nx] == 0) isBorder = true;
		if (map[ny][nx] == 1) Sorting(ny, nx, label);
	}
	
	if (isBorder)
		borders[label].emplace_back(y, x);
}

int BFS(int label)
{
	queue<pair<pair<int,int>, int>> q;
	bool visited[100][100] = { false };

	for (auto& pos : borders[label])
	{
		q.push({ pos, 0 });
		visited[pos.first][pos.second] = true;
	}

	while (!q.empty())
	{
		auto [pos, dist] = q.front(); q.pop();
		int y = pos.first, x = pos.second;

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (visited[ny][nx]) continue;

			if (map[ny][nx] != 0 && map[ny][nx] != label)
				return dist;

			if (map[ny][nx] == 0)
			{
				visited[ny][nx] = true;
				q.push({ {ny, nx }, dist + 1 });
			}
		}
	}

	return 1e9;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. 입력 및 저장
	cin >> N;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> map[y][x];


	// 2. 영토 구분
	int label = 2;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			if (map[y][x] == 1)
				Sorting(y, x, label++);


	// 3. BFS
	int answer = 1e9;
	for (int i = 2; i < label; i++)
		answer = min(answer, BFS(i));

	cout << answer;
	return 0;
}