#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, L, R, days = 0;
int map[50][50];
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

bool BFS(int y, int x, vector<vector<bool>>& visited) // 연합 찾고 인구 이동
{
	vector<pair<int, int>> list; // 연합 국가 목록
	queue<pair<int, int>> q;
	q.push({ y, x });
	visited[y][x] = true;
	list.push_back({ y, x });
	int sum = map[y][x]; // 연합 인구 수
	int size = 1; // 연합 국가 수

	while (!q.empty())
	{
		pair<int, int> info = q.front(); q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = info.first + dy[i];
			int nx = info.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx]) continue;

			int diff = abs(map[info.first][info.second] - map[ny][nx]); // 두 국가의 인구수 차이
			if (diff < L || diff > R) continue;

			q.push({ ny, nx });
			visited[ny][nx] = true;
			list.push_back({ ny, nx }); // 연합된 국가의 좌표 저장
			sum += map[ny][nx];
			size++;
		}
	}

	if (size <= 1) return false;

	int avg = sum / size; // 각 칸의 인구수
	for (auto& l : list)
	{
		map[l.first][l.second] = avg;
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> L >> R;

	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> map[y][x];

	while (true)
	{
		vector<vector<bool>> visited(N, vector<bool>(N, false));
		bool moved = false; // 이번 턴에 인구 이동이 있었는지 체크

		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				if (!visited[y][x])
					if (BFS(y, x, visited))
						moved = true; // 한 번이라도 인구 이동이 발생하면 true

		if (!moved) break; // 인구 이동이 없으면 종료
		days++; // 하루 증가
	}

	cout << days;
	return 0;
}