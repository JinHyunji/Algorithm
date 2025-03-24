#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Shark
{
	int y, x, dist;
	bool operator>(const Shark& other) const
	{
		if (dist != other.dist) return dist > other.dist;	// 거리 우선
		if (y != other.y) return y > other.y;				// 위쪽 우선
		return x > other.x;									// 왼쪽 우선
	}
};

int N, timeSpent = 0, eaten = 0, sharkSize = 2;
int map[20][20];
pair<int, int> sharkPos;
int dy[] = { -1, 0, 1, 0 }, dx[] = { 0, -1, 0, 1 };

// BFS로 최단 거리 물고기 찾기
bool BFS()
{
	priority_queue<Shark, vector<Shark>, greater<Shark>> pq;
	vector<vector<int>> dist(N, vector<int>(N, -1));

	pq.push({ sharkPos.first, sharkPos.second, 0 });
	dist[sharkPos.first][sharkPos.second] = 0;

	while (!pq.empty())
	{
		Shark cur = pq.top(); pq.pop();

		// 먹을 수 있는 물고기 발견
		if (map[cur.y][cur.x] > 0 && map[cur.y][cur.x] < sharkSize)
		{
			map[cur.y][cur.x] = 0; // 물고기 제거
			sharkPos = { cur.y, cur.x };
			timeSpent += cur.dist;
			eaten++;

			if (eaten == sharkSize)
			{
				sharkSize++;
				eaten = 0;
			}

			return true; // 물고기를 먹었으므로 다시 탐색 시작
		}

		// 사방 탐색
		for (int i = 0; i < 4; i++)
		{
			int ny = cur.y + dy[i], nx = cur.x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (dist[ny][nx] != -1 || map[ny][nx] > sharkSize) continue; // 방문했거나 더 큰 물고기는 탐색 패스

			dist[ny][nx] = cur.dist + 1;
			pq.push({ ny, nx, cur.dist + 1 });
		}
	}

	return false; // 더 이상 먹을 물고기가 없음
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> map[y][x];
			if (map[y][x] == 9)
			{
				sharkPos = { y, x };
				map[y][x] = 0;
			}
		}
	}

	while (BFS()); // 먹을 수 있는 물고기가 있으면 계속 반복

	cout << timeSpent;
	return 0;
}