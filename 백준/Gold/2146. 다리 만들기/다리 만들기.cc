#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };

int N;
int map[100][100];
vector<vector<pair<int, int>>> lands;

int distance(int color)
{
	queue<tuple<int, int, int>> q;
	bool visited[100][100] = { false };

	for (auto [x, y] : lands[color])
	{
		q.emplace(x, y, 0);
		visited[x][y] = true;
	}

	while (!q.empty())
	{
		auto [x, y, dist] = q.front(); q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (map[nx][ny] == color || visited[nx][ny]) continue;

			if (map[nx][ny] == 0)
			{
				q.push({ nx, ny, dist + 1 });
				visited[nx][ny] = true;
			}
			else
			{
				return dist;
			}
		}
	}

	return -1;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < N; y++)
		{
			cin >> map[x][y];
		}
	}

	// 영역 구분하기
	queue<pair<int, int>> tempQ;
	lands.resize(10000);
	int color = 1;

	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < N; y++)
		{
			if (map[x][y] == 1) // 영역 구분 안했으면
			{
				// 색상 정하기
				color++;

				// 연결된 섬 모두 마킹
				tempQ.push({ x, y });
				map[x][y] = color;

				while (!tempQ.empty())
				{
					auto [x, y] = tempQ.front(); tempQ.pop();

					bool isSea = false;

					for (int i = 0; i < 4; i++)
					{
						int nx = x + dx[i];
						int ny = y + dy[i];

						if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
						if (map[nx][ny] == 0)
						{
							isSea = true;
							continue;
						}
						if (map[nx][ny] == 1)
						{
							tempQ.push({ nx, ny });
							map[nx][ny] = color;
						}
					}

					if (isSea)
					{
						lands[color].emplace_back(x, y);
					}
				}
			}
		}
	}

	int answer = INT32_MAX;
	for (int i = 2; i <= color; i++)
	{
		answer = min(answer, distance(i));
	}


	cout << answer;
	return 0;
}