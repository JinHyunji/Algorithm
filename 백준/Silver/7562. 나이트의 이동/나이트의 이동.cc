#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
using namespace std;

int T, N;
string output;
pair<int, int> curr, dest;
int dy[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

void BFS()
{
	bool visited[300][300] = { false };
	queue<tuple<int, int, int>> q;
	q.push({ curr.first, curr.second, 0 });
	visited[curr.first][curr.second] = true;

	while (!q.empty())
	{
		auto [x, y, move] = q.front();
		q.pop();

		if (x == dest.first && y == dest.second)
		{
			output += to_string(move) + "\n";
			break;
		}

		for (int i = 0; i < 8; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (visited[nx][ny]) continue;

			q.push({ nx, ny, move + 1 });
			visited[nx][ny] = true;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> N;

		int x, y;

		cin >> x >> y;
		curr = make_pair(x, y);

		cin >> x >> y;
		dest = make_pair(x, y);

		BFS();
	}

	cout << output;
	return 0;
}