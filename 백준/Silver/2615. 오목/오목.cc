#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;

int dy[]{ 1, 0, -1, 1 };
int dx[]{ 0, 1, 1, 1 };

vector<vector<int>> goBoard(19, vector<int>(19));

bool checkWin(int y, int x, int player);

int main()
{
	// 입출력 성능 향상
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 입력
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			cin >> goBoard[i][j];
		}
	}

	// 로직

	for (int i = 0; i < 19; i++)
		for (int j = 0; j < 19; j++)
			if (goBoard[i][j] == 1 || goBoard[i][j] == 2)
				if (checkWin(i, j, goBoard[i][j]))
					return 0;

	cout << 0 << endl;
	return 0;
}

bool checkWin(int y, int x, int player)
{
	for (int dir = 0; dir < 4; dir++)
	{
		int cnt = 1;
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		while (ny >= 0 && ny < 19 && nx >= 0 && nx < 19 && goBoard[ny][nx] == player)
		{
			cnt++;
			ny += dy[dir];
			nx += dx[dir];
		}

		ny = y - dy[dir];
		nx = x - dx[dir];

		while (ny >= 0 && ny < 19 && nx >= 0 && nx < 19 && goBoard[ny][nx] == player)
		{
			cnt++;
			ny -= dy[dir];
			nx -= dx[dir];
		}

		if (cnt == 5)
		{
			int sy = y, sx = x;
			while (sy - dy[dir] >= 0 && sx - dx[dir] >= 0 &&
				goBoard[sy - dy[dir]][sx - dx[dir]] == player)
			{
				sy -= dy[dir];
				sx -= dx[dir];
			}

			cout << player << endl;
			cout << sy + 1 << " " << sx + 1 << endl;
			return true;
		}
	}
	return false;
}