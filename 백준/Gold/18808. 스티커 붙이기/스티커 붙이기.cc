#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int N, M, K;
int notebook[50][50];
vector<vector<vector<int>>> sticker;

void IsAttached(int index)
{
	for (int rot = 0; rot < 4; rot++)
	{
		// Sticker Width, Height
		int R = (int)sticker[index].size();
		int C = (int)sticker[index][0].size();

		for (int x = 0; x <= N - R; x++)
		{
			for (int y = 0; y <= M - C; y++)
			{
				bool isAllCorrect = false;
				for (int r = 0; r < R; r++)
				{
					for (int c = 0; c < C; c++)
					{
						int nx = x + r;
						int ny = y + c;

						if (notebook[nx][ny] == 1 && sticker[index][r][c] == 1)
						{
							isAllCorrect = true;
							break;
						}

					}

					if (isAllCorrect)
					{
						break;
					}
				}

				if (isAllCorrect) continue;
				for (int r = 0; r < R; r++)
				{
					for (int c = 0; c < C; c++)
					{
						int nx = x + r;
						int ny = y + c;

						if (sticker[index][r][c] == 1)
						{
							notebook[nx][ny] = 1;
						}

					}
				}
				return;
			}
		}

		// RightTurn
		vector<vector<int>> rotated(C, vector<int>(R));
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				rotated[j][R - 1 - i] = sticker[index][i][j];
			}
		}

		sticker[index] = rotated;
	}
	return;
}

int CountSticker()
{
	int cnt = 0;
	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < M; y++)
		{
			if (notebook[x][y] == 1)
			{
				cnt++;
			}
		}
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;
	sticker.resize(K);

	for (int i = 0; i < K; i++)
	{
		int R, C;
		cin >> R >> C;
		vector<vector<int>> st(R, vector<int>(C));

		for (int x = 0; x < R; x++)
			for (int y = 0; y < C; y++)
				cin >> st[x][y];

		sticker[i] = st;
	}

	for (int i = 0; i < K; i++)
	{
		IsAttached(i);
	}

	cout << CountSticker();
}