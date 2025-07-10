#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int answer = 0;
char field[12][6];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

bool bfs(int x, int y, char color, vector<vector<bool>>& visited)
{
	vector<pair<int, int>> py;
	py.emplace_back(x, y);
	int cnt = 1;

	queue<pair<int, int>> q;
	q.emplace(x, y);
	visited[x][y] = true;

	while (!q.empty())
	{
		auto [sx, sy] = q.front(); q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = sx + dx[i], ny = sy + dy[i];

			if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;
			if (field[nx][ny] != color || visited[nx][ny]) continue;

			q.emplace(nx, ny);
			visited[nx][ny] = true;
			cnt++;
			py.emplace_back(nx, ny);
		}
	}

	if (cnt >= 4)
	{
		for (auto [i, j] : py)
			field[i][j] = '.';
		return true;
	}

	return false;
}

bool bomb()
{
	vector<vector<bool>> visited(12, vector<bool>(6, false));
	int cnt = 0;

	for (int x = 0; x < 12; x++)
	{
		for (int y = 0; y < 6; y++)
		{
			if (field[x][y] == '.' || visited[x][y]) continue;
			if (bfs(x, y, field[x][y], visited)) cnt++;
		}
	}

	if (cnt > 0)
	{
		answer++;
		return true;
	}

	return false;
}

void gravity()
{
	for (int c = 0; c < 6; c++)
	{
		for (int r = 11; r >= 0; r--)
		{
			if (r == 11) continue;
			if (field[r][c] == '.') continue;

			char color = field[r][c];
			int idx = r;
			while (idx < 12 && field[idx + 1][c] == '.')
			{
				field[idx + 1][c] = color;
				field[idx][c] = '.';
				idx++;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int x = 0; x < 12; x++)
	{
		string str;
		cin >> str;
		for (int y = 0; y < 6; y++)
		{
			field[x][y] = str[y];
		}
	}

	while (true)
	{
		if (!bomb()) break;
		gravity();
	}

	cout << answer;
}