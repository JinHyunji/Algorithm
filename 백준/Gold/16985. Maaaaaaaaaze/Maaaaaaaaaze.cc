#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

int map[5][5][5];
int temp[5][5][5];
int newTemp[5][5][5];

vector<tuple<int, int, int>> Start = { {0,0,0}, {0,0,4}, {0,4,0}, {0,4,4}, {4,4,4}, {4,4,0}, {4,0,4},{4,0,0} };
vector<tuple<int, int, int>> End = { {4,4,4}, {4,4,0}, {4,0,4}, {4,0,0}, {0,0,0}, {0,0,4}, {0,4,0}, {0,4,4} };

// 상 하 좌 우 위 아래
int dx[6] = { 0, 0, 0, 0, -1, 1 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dz[6] = { -1, 1, 0, 0, 0, 0 };

void Rotate(int x, int dir) // 해당 높이의 배열을 dir 방향으로 회전하는 함수
{
	int rotated[5][5][5];
	copy(&temp[0][0][0], &temp[0][0][0] + 5 * 5 * 5, &rotated[0][0][0]);

	if (dir == 0)
	{
		return;
	}
	else if (dir == 1)
	{
		for (int y = 0; y < 5; y++)
		{
			for (int z = 0; z < 5; z++)
			{
				rotated[x][y][z] = temp[x][z][4 - y];
			}
		}
	}
	else if (dir == 2)
	{
		for (int y = 0; y < 5; y++)
		{
			for (int z = 0; z < 5; z++)
			{
				rotated[x][y][z] = temp[x][4 - y][4 - z];
			}
		}
	}
	else
	{
		for (int y = 0; y < 5; y++)
		{
			for (int z = 0; z < 5; z++)
			{
				rotated[x][y][z] = temp[x][4 - z][y];
			}
		}
	}

	for (int y = 0; y < 5; y++)
	{
		for (int z = 0; z < 5; z++)
		{
			temp[x][y][z] = rotated[x][y][z];
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int x = 0; x < 5; x++)
		for (int y = 0; y < 5; y++)
			for (int z = 0; z < 5; z++)
				cin >> map[x][y][z];

	int minDist = INT32_MAX;
	for (int i = 0; i < (1 << 10); i++)
	{
		copy(&map[0][0][0], &map[0][0][0] + 5 * 5 * 5, &temp[0][0][0]);

		// 판 돌리기
		int brute = i;
		for (int k = 0; k < 5; k++)
		{
			int dir = brute % 4;
			brute /= 4;
			Rotate(k, dir);
		}

		// 판 쌓기
		vector<int> arr(5);
		for (int i = 0; i < 5; i++)
			arr[i] = i;
		do
		{
			copy(&temp[0][0][0], &temp[0][0][0] + 5 * 5 * 5, &newTemp[0][0][0]);

			for (int i = 0; i < 5; i++)
				for (int y = 0; y < 5; y++)
					for (int z = 0; z < 5; z++)
						newTemp[i][y][z] = temp[arr[i]][y][z];

			// 입구 선택하기
			for (int i = 0; i < 8; i++)
			{
				// 출구까지 최소 이동 거리 갱신하기
				queue<tuple<int, int, int, int>> q; // x, y, z, dist
				bool visited[5][5][5];
				fill(&visited[0][0][0], &visited[0][0][0] + 5 * 5 * 5, false);

				auto [sx, sy, sz] = Start[i];
				auto [ex, ey, ez] = End[i];

				if (newTemp[sx][sy][sz] == 0 || newTemp[ex][ey][ez] == 0) continue;

				q.push({ sx, sy, sz, 0 });
				visited[sx][sy][sz] = true;

				while (!q.empty())
				{
					auto [x, y, z, dist] = q.front(); q.pop();

					if (x == ex && y == ey && z == ez)
					{
						minDist = min(minDist, dist);
						break;
					}

					if (minDist == 12)
					{
						cout << 12;
						return 0;
					}

					for (int i = 0; i < 6; i++)
					{
						int nx = x + dx[i];
						int ny = y + dy[i];
						int nz = z + dz[i];

						if (nx < 0 || ny < 0 || nz < 0 || nx >= 5 || ny >= 5 || nz >= 5) continue;
						if (newTemp[nx][ny][nz] == 0 || visited[nx][ny][nz]) continue;

						q.push({ nx,ny,nz,dist + 1 });
						visited[nx][ny][nz] = true;
					}
				}
			}

		} while (next_permutation(arr.begin(), arr.end()));
	}

	cout << (minDist == INT32_MAX ? -1 : minDist);
}