#include <iostream>
#include <vector>
#include <queue>
#include <cstring> // memset 사용
using namespace std;

int N, M, times;
int map[100][100];
bool visited[100][100];
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
vector<pair<int, int>> willBeMelted; // 메모리 재사용


void FindExternalAir()
{
	queue<pair<int, int>> q;
	q.push({ 0, 0 });

	// visited 배열을 memset으로 초기화 (더 빠름)
	memset(visited, false, sizeof(visited));

	visited[0][0] = true;

	while (!q.empty())
	{
		auto [y, x] = q.front(); q.pop(); // unpack 사용

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

void CheckMeltingPoint()
{
	willBeMelted.clear(); // 이전 값 초기화 후 재사용

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
}

void MeltingCheese()
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

	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			cin >> map[y][x];

	while (true)
	{
		FindExternalAir();
		CheckMeltingPoint();
		if (willBeMelted.empty()) break;
		MeltingCheese();
		times++;
	}

	cout << times;
	return 0;
}