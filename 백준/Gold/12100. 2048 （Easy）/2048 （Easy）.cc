#include <iostream>
#include <algorithm>
using namespace std;

int N;
int board[20][20];
int board2[20][20];

void rotate()
{
	int temp[20][20];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			temp[i][j] = board2[j][N - 1 - i];
	for (int x = 0; x < N; x++)
		for (int y = 0; y < N; y++)
			board2[x][y] = temp[x][y];
}

void tilt(int dir)
{
	while (dir--) rotate();
	for (int i = 0; i < N; i++)
	{
		int tilted[20] = {};
		int idx = 0;
		for (int j = 0; j < N; j++)
		{
			if (board2[i][j] == 0) continue;
			if (tilted[idx] == 0)
				tilted[idx] = board2[i][j];
			else if (tilted[idx] == board2[i][j])
				tilted[idx++] *= 2;
			else
				tilted[++idx] = board2[i][j];
		}

		for (int j = 0; j < N; j++)
			board2[i][j] = tilted[j];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int x = 0; x < N; x++)
		for (int y = 0; y < N; y++)
			cin >> board[x][y];

	int mx = 0;
	for (int i = 0; i < 1024; i++)
	{
		for (int x = 0; x < N; x++)
			for (int y = 0; y < N; y++)
				board2[x][y] = board[x][y];

		int brute = i;
		for (int k = 0; k < 5; k++)
		{
			int dir = brute % 4;
			brute /= 4;
			tilt(dir);
		}

		for (int x = 0; x < N; x++)
			for (int y = 0; y < N; y++)
				mx = max(mx, board2[x][y]);
	}

	cout << mx;
}