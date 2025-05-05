#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <string.h>
using namespace std;

#define MAX 100

int T, H, W;
char map[MAX][MAX];
bool visited[MAX][MAX];
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

bool bfs(unordered_set<char>& keys, int& answer)
{
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	unordered_map<char, vector<pair<int, int>>> doors;
	bool newFoundKey = false;

	for (int y = 0; y < H; y++)
	{
		for (int x = 0; x < W; x++)
		{
			if (y == 0 || x == 0 || y == H - 1 || x == W - 1)
			{
				char ch = map[y][x];

				if (ch == '*' || visited[y][x]) continue;

				if ('A' <= ch && ch <= 'Z')
				{
					if (!keys.count(ch + 32))
					{
						doors[ch].emplace_back(y, x);
						continue;
					}
				}

				q.emplace(y, x);
				visited[y][x] = true;
			}
		}
	}

	while (!q.empty())
	{
		auto [y, x] = q.front(); q.pop();

		char ch = map[y][x];

		if (ch == '$')
		{
			answer++;
			map[y][x] = '.';
		}

		if ('a' <= ch && ch <= 'z')
		{
			if (!keys.count(ch))
			{
				keys.insert(ch);
				newFoundKey = true;

				char upper = ch - 32;
				for (auto& pos : doors[upper])
				{
					q.emplace(pos);
					visited[pos.first][pos.second] = true;
				}
			}

			map[y][x] = '.';
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i], nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
			if (map[ny][nx] == '*' || visited[ny][nx]) continue;

			char next = map[ny][nx];

			if ('A' <= next && next <= 'Z')
			{
				if (!keys.count(next + 32))
				{
					doors[next].emplace_back(ny, nx);
					continue;
				}
			}

			q.emplace(ny, nx);
			visited[ny][nx] = true;
		}
	}

	return newFoundKey;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;

	while (T--)
	{
		cin >> H >> W;

		for (int y = 0; y < H; y++)
		{
			string row;
			cin >> row;
			for (int x = 0; x < W; x++)
			{
				map[y][x] = row[x];
			}
		}

		unordered_set<char> keys;
		string str;
		cin >> str;
		if (str != "0")
			for (char& key : str)
				keys.insert(key);

		int answer = 0;
		while (true)
		{
			bool found = bfs(keys, answer);
			if (!found) break;
		}

		cout << answer << endl;
	}

	return 0;
}