#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

int N, M, year = 0;
bool bIsSeperated = false;
int map[300][300];


bool IsAllMelted()
{
	for (int x = 1; x < N - 1; x++)
	{
		for (int y = 1; y < M - 1; y++)
		{
			if (map[x][y] != 0)
				return false;
		}
	}

	return true;
}

bool IsSeperated()
{
	bool visited[300][300] = { false };
	queue<pair<int, int>> q;
	int landCnt = 0;

	for (int x = 1; x < N - 1; x++)
	{
		for (int y = 1; y < M - 1; y++)
		{
			if (map[x][y] != 0 && !visited[x][y])
			{
				q.push({ x, y });
				visited[x][y] = true;

				while (!q.empty())
				{
					auto [x, y] = q.front(); q.pop();

					for (int i = 0; i < 4; i++)
					{
						int nx = x + dx[i];
						int ny = y + dy[i];

						if (map[nx][ny] == 0 || visited[nx][ny]) continue;

						q.push({ nx, ny });
						visited[nx][ny] = true;
					}
				}

				landCnt++;
			}
		}
	}

	if (landCnt >= 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Melting()
{
	int temp[300][300] = { 0, };

	for (int x = 1; x < N - 1; x++)
	{
		for (int y = 1; y < M - 1; y++)
		{
			if (map[x][y] != 0)
			{
				int sea = 0;
				for (int i = 0; i < 4; i++)
				{
					int nx = x + dx[i];
					int ny = y + dy[i];

					if (map[nx][ny] == 0)
					{
						sea++;
					}
				}

				temp[x][y] = max(0, map[x][y] - sea);
			}
		}
	}

	copy(&temp[0][0], &temp[0][0] + 300 * 300, &map[0][0]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < M; y++)
		{
			cin >> map[x][y];
		}
	}

	while (true)
	{
		if (IsAllMelted())
		{
			break;
		}

		if (IsSeperated())
		{
			bIsSeperated = true;
			break;
		}

		Melting();
		year++;
	}

	if (bIsSeperated)
	{
		cout << year;
	}
	else
	{
		cout << 0;
	}

	return 0;
}