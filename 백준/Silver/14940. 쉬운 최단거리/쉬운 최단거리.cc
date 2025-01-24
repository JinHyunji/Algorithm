#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, desX, desY;
int dy[]{ -1, 1, 0, 0 };
int dx[]{ 0, 0, -1, 1 };
vector<vector<int>> map;
vector<vector<int>> answer_map;

void BFS(int desY, int desX);

int main()
{
	// 입출력 성능 개선
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 입력
	cin >> N >> M;

	map.resize(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];

			// 목표 지점 저장
			if (map[i][j] == 2)
			{
				desY = i;
				desX = j;
			}
		}
	}

	// 로직
	answer_map.resize(N, vector<int>(M, 0));
	BFS(desY, desX);

	// 출력
	for (vector<int> y : answer_map)
	{
		for (int x : y)
		{
			cout << x << " ";
		}
		cout << endl;
	}
}

void BFS(int desY, int desX)
{
	vector<vector<bool>> visited(N, vector<bool>(M, false));
	queue<vector<int>> q;
	q.push({ desY, desX, 0 });
	visited[desY][desX] = true;

	while (!q.empty())
	{
		int y = q.front()[0];
		int x = q.front()[1];
		int dist = q.front()[2]; q.pop();

		answer_map[y][x] = dist;

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= 0 && ny < N && nx >= 0 && nx < M && map[ny][nx] == 1 && !visited[ny][nx])
			{
				visited[ny][nx] = true;
				q.push({ ny, nx, dist + 1 });
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!visited[i][j] && map[i][j] == 1)
			{
				answer_map[i][j] = -1;
			}
		}
	}
}