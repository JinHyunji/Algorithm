#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int R, C, maxDist = 1;
vector<vector<int>> board;
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

		if (visited[board[ny][nx] - 65])
		{
			maxDist = max(maxDist, dist);
			continue;
		}

		visited[board[ny][nx] - 65] = true;
		DFS(nx, ny, dist + 1);
		visited[board[ny][nx] - 65] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> R >> C;

	board.resize(R, vector<int>(C, 0));

	for (int r = 0; r < R; r++)
	{
		string input;
		cin >> input;

		for (int c = 0; c < C; c++)
		{
			board[r][c] = input[c];
		}
	}

	visited[board[0][0] - 65] = true;
	DFS(0, 0, 1);
	cout << maxDist;
	return 0;
}