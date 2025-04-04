#include <iostream>
#include <queue>
#include <tuple>
#include <string>
#include <vector>
using namespace std;

int T, W, H;
string output;
char map[1000][1000];
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
pair<int, int> startPos;
vector<pair<int, int>> firePos;

void BFS()
{
	queue<tuple<int, int, int, int>> q;
	bool visited[1000][1000] = { false };
	for (auto& fire : firePos)
		q.push({ fire.first, fire.second, 0, 0 });
	q.push({ startPos.first, startPos.second, 0, 1 });
	visited[startPos.first][startPos.second] = true;

	while (!q.empty())
	{
		auto [y, x, times, id] = q.front();
		q.pop();

		if (id == 1 && (y == 0 || x == 0 || y == H - 1 || x == W - 1))
		{
			output += to_string(times + 1) + "\n";
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
			if (map[ny][nx] == '#' || map[ny][nx] == '*') continue;

			if (id == 1)
			{
				if (visited[ny][nx]) continue;
				visited[ny][nx] = true;
			}
			else
			{
				map[ny][nx] = '*';
			}
			q.push({ ny, nx, times + 1, id });
		}
	}

	output += "IMPOSSIBLE\n";
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> W >> H;

		for (int y = 0; y < H; y++)
		{
			for (int x = 0; x < W; x++)
			{
				cin >> map[y][x];
				if (map[y][x] == '@') startPos = { y, x };
				else if (map[y][x] == '*') firePos.push_back({ y, x });
			}
		}

		BFS();


		firePos.clear();
	}

	cout << output;
	return 0;
}