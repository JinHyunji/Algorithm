#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>
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
	bool newKeyFound = false;

	// 외곽에서 시작
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
					if (keys.count(ch + 32))
					{
						q.emplace(y, x);
						visited[y][x] = true;
					}
					else
					{
						doors[ch].emplace_back(y, x);
						continue;
					}
				}
				else
				{
					q.emplace(y, x);
					visited[y][x] = true;
				}
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
				newKeyFound = true;

				// 저장해뒀던 문 위치에 다시 접근 가능
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
			if (visited[ny][nx] || map[ny][nx] == '*') continue;

			char next = map[ny][nx];

			if ('A' <= next && next <= 'Z')
			{
				if (keys.count(next+32))
				{
					visited[ny][nx] = true;
					q.emplace(ny, nx);
				}
				else
				{
					doors[next].emplace_back(ny, nx);
				}
			}
			else
			{
				visited[ny][nx] = true;
				q.emplace(ny, nx);
			}
		}
	}

	return newKeyFound;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;

	string output;
	for (int t = 0; t < T; t++)
	{
		cin >> H >> W;
		
		for (int y = 0; y < H; y++)
		{
			string str;
			cin >> str;
			for (int x = 0; x < W; x++)
				map[y][x] = str[x];
		}

		unordered_set<char> keys;
		string str;
		cin >> str;

		if (str != "0")
			for (int i = 0; i < str.size(); i++)
				keys.insert(str[i]);

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