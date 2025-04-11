#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int K, W, H;
int map[200][200];
bool visited[200][200][31] = {false};
int dy_8[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dx_8[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy_4[] = { 0, 1, 0, -1 };
int dx_4[] = { 1, 0, -1, 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> K >> W >> H;

	for (int y = 0; y < H; y++)
		for (int x = 0; x < W; x++)
			cin >> map[y][x];

	queue<tuple<int, int, int, int>> q; // (y, x, dist, k)
	q.push({ 0, 0, 0, K });
	visited[0][0][K] = true;

	while (!q.empty())
	{
		auto [y, x, dist, k] = q.front(); q.pop();

		if (y == H - 1 && x == W - 1)
		{
			cout << dist;
			return 0;
		}

		for (int i = 0; i < 8; i++)
		{
			if (k < 1)
				continue;

			int ny = y + dy_8[i];
			int nx = x + dx_8[i];

			if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
			if (visited[ny][nx][k - 1] || map[ny][nx] == 1) continue;

			visited[ny][nx][k - 1] = true;
			q.push({ ny, nx, dist + 1, k - 1 });
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy_4[i];
			int nx = x + dx_4[i];

			if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
			if (visited[ny][nx][k] || map[ny][nx] == 1) continue;

			visited[ny][nx][k] = true;
			q.push({ ny, nx, dist + 1, k });
		}
	}

	cout << -1;
	return 0;
}