#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstdint>
#include <algorithm>
using namespace std;
using ll = long long;

int R, C, maxDist = 1;
vector<vector<char>> board;
bool visited[26];
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

void DFS(int x, int y, int dist)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;

		if (visited[board[ny][nx] - 'A'])
		{
			maxDist = max(maxDist, dist);
			continue;
		}

		visited[board[ny][nx] - 'A'] = true;
		DFS(nx, ny, dist + 1);
		visited[board[ny][nx] - 'A'] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> R >> C;

	board.resize(R, vector<char>(C));

	for (int r = 0; r < R; r++)
	{
		string input;
		cin >> input;

		for (int c = 0; c < C; c++)
		{
			board[r][c] = input[c];
		}
	}

	visited[board[0][0] - 'A'] = true;
	DFS(0, 0, 1);
	cout << maxDist;
	return 0;
}