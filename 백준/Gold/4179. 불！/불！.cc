#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <tuple>
using namespace std;

int R, C, minTimes = INT32_MAX;
char map[1000][1000];
bool visited[1000][1000];
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
pair<int, int> jh;
vector<pair<int, int>> fires;

bool IsCorner(int y, int x)
{
	if (y == 0 || x == 0 || y == R - 1 || x == C - 1) return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> R >> C;
	for (int y = 0; y < R; y++)
	{
		string input;
		cin >> input;
		for (int x = 0; x < C; x++)
		{
			map[y][x] = input[x];
			if (map[y][x] == 'J') jh = make_pair(y, x);
			else if (map[y][x] == 'F') fires.push_back(make_pair(y, x));
		}
	}

	queue<tuple<int, int, int, int>> q;
	for (pair<int, int> fire : fires)
		q.push({ fire.first, fire.second, 0, 0 });
	q.push({ jh.first, jh.second, 0, 1 }); // y, x, time, J or F
	visited[jh.first][jh.second] = true;

	while (!q.empty())
	{
		auto [y, x, times, id] = q.front();
		q.pop();

		if (id == 1 && IsCorner(y, x))
		{
			cout << times + 1;
			return 0;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (id == 0) // fire
			{
				if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
				if (map[ny][nx] == '#' || map[ny][nx] == 'F') continue;
				q.push({ ny, nx, times, id });
				map[ny][nx] = 'F';
			}
			else // J
			{
				if (map[ny][nx] == 'F' || map[ny][nx] == '#' || visited[ny][nx]) continue;
				q.push({ ny, nx, times + 1, id });
				visited[ny][nx] = true;
			}
		}
	}

	cout << "IMPOSSIBLE";
	return 0;
}