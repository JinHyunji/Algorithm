#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, times;
int map[100][100];
bool visited[100][100];
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };


void FindExternalAir()
{
	queue<pair<int, int>> q;
	q.push({ 0, 0 });

	// visited 배열 초기화
	for (int i = 0; i < N; i++)
		fill(visited[i], visited[i] + M, false);

	visited[0][0] = true;

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] || map[ny][nx] == 1) continue;

			visited[ny][nx] = true;
			q.push({ ny, nx });
		}
	}
}

vector<pair<int, int>> CheckMeltingPoint()
{
	vector<pair<int, int>> willBeMelted;

	for (int y = 1; y < N; y++)
	{
		for (int x = 1; x < M; x++)
		{
			if (map[y][x] == 1)
			{
				int air = 0;
				for (int k = 0; k < 4; k++)
				{
					int ny = y + dy[k];
					int nx = x + dx[k];

					if (map[ny][nx] == 0 && visited[ny][nx])
						air++;
				}

				if (air >= 2)
					willBeMelted.push_back(make_pair(y, x));
			}
		}
	}
	
	return willBeMelted;
}

void MeltingCheese(vector<pair<int, int>>& willBeMelted)
{
	for (auto& p : willBeMelted)
	{
		map[p.first][p.second] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	// 입력
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int input;
			cin >> input;
			map[i][j] = input;
		}
	}

	while (true)
	{
		FindExternalAir();

		vector<pair<int, int>> willBeMelted = CheckMeltingPoint();

		if (willBeMelted.empty()) break;

		MeltingCheese(willBeMelted);
		times++;
	}

	cout << times;
	return 0;
}