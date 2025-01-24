#include <iostream>
#include <vector>
using namespace std;

int N, M;
int dy[]{ -1, 1, 0, 0 };
int dx[]{ 0, 0, -1, 1 };
vector<vector<int>> map;

bool IsAllMelted();
void MeltIcebergs();
bool IsSeparate();
void DFS(int y, int x, vector<vector<bool>>& visited);

int main()
{
	// 입력
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	map.resize(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	int year = 0;

	while (true)
	{
		// 빙산이 분리되었는지 확인
		if (IsSeparate())
		{
			cout << year;
			return 0;
		}

		// 빙산이 모두 녹았는지 확인
		if (IsAllMelted())
		{
			cout << 0;
			return 0;
		}

		// 빙산 녹이기
		MeltIcebergs();
		year++;
	}

	return 0;
}

bool IsAllMelted()
{
	for (int i = 0;i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] > 0)
				return false;
		}
	}
	return true;
}

void MeltIcebergs()
{
	vector<vector<int>> temp_map = map;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] > 0)
			{
				int cnt = 0;

				for (int k = 0; k < 4; k++)
				{
					int ny = i + dy[k];
					int nx = j + dx[k];

					if (ny >= 0 && ny < N && nx >= 0 && nx < M && map[ny][nx] == 0)
					{
						cnt++;
					}
				}

				temp_map[i][j] = max(0, temp_map[i][j] - cnt);
			}
		}
	}

	map = temp_map;
}

bool IsSeparate()
{
	vector<vector<bool>> visited(N, vector<bool>(M, 0));
	int cnt = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] > 0 && !visited[i][j])
			{
				cnt++;
				if (cnt > 1) return true;
				DFS(i, j, visited);
			}
		}
	}

	return false;
}

void DFS(int y, int x, vector<vector<bool>>& visited)
{
	visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= 0 && ny < N && nx >= 0 && nx < M && map[ny][nx] > 0 && !visited[ny][nx])
		{
			DFS(ny, nx, visited);
		}
	}
}