#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M; // 열과 행
vector<vector<vector<pair<int, int>>>> switchMap; // 스위치 정보가 담긴 맵
vector<vector<bool>> lightMap; // 불 켜진 정보가 담긴 맵
vector<vector<bool>> visited; // 방문 여부
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

bool InRange(int y, int x)
{
	return (y >= 1 && x >= 1 && y <= M && x <= N);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	switchMap.resize(M + 1, vector<vector<pair<int, int>>>(N + 1));
	lightMap.resize(M + 1, vector<bool>(N + 1));
	visited.resize(M + 1, vector<bool>(N + 1));

	for (int i = 0; i < M; i++)
	{
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		switchMap[y][x].emplace_back(b, a);
	}

	queue<pair<int, int>> q;
	q.emplace(1, 1);
	lightMap[1][1] = true;
	visited[1][1] = true;

	int answer = 1;
	while (!q.empty())
	{
		auto [y, x] = q.front(); q.pop();

		// 스위치 켜기
		for (auto [b, a] : switchMap[y][x])
		{
			if (!lightMap[b][a])
			{
				lightMap[b][a] = true;
				answer++;

				// 새로 불 켜진 방이 인접 방문 가능하면 큐에 넣기
				for (int i = 0; i < 4; i++)
				{
					int ny = b + dy[i];
					int nx = a + dx[i];

					if (InRange(ny, nx) && visited[ny][nx])
					{
						visited[b][a] = true;
						q.emplace(b, a);
						break;
					}
				}
			}
		}

		// 상하좌우 이동
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (!InRange(ny, nx)) continue; // 탐색 범위를 벗어나면 패스
			if (!lightMap[ny][nx] || visited[ny][nx]) continue; // 불이 꺼져있거나 방문했으면 패스

			visited[ny][nx] = true;
			q.emplace(ny, nx);
		}
	}

	cout << answer;

	return 0;
}