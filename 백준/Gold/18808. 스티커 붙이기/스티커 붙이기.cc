#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int N, M, K;
int notebook[50][50];
vector<vector<vector<int>>> sticker;

vector<vector<int>> rotateRight(const vector<vector<int>>& mat)
{
	int R = mat.size(), C = mat[0].size();
	vector<vector<int>> rotated(C, vector<int>(R));
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			rotated[j][R - 1 - i] = mat[i][j];
	return rotated;
}

void IsAttached(int index)
{
	for (int rot = 0; rot < 4; rot++)
	{
		// Sticker Width, Height
		int R = (int)sticker[index].size(), C = (int)sticker[index][0].size();

		for (int x = 0; x <= N - R; x++)
		{
			for (int y = 0; y <= M - C; y++)
			{
				bool canAttack = true;
				for (int r = 0; r < R && canAttack; r++)
				{
					for (int c = 0; c < C; c++)
					{
						if (notebook[x + r][y + c] == 1 && sticker[index][r][c] == 1)
						{
							canAttack = false;
							break;
						}

					}
				}

				if (!canAttack) continue;

				// Attach Sticker
				for (int r = 0; r < R; r++)
					for (int c = 0; c < C; c++)
						if (sticker[index][r][c] == 1)
							notebook[x + r][y + c] = 1;

				return;
			}
		}

		// RightTurn
		sticker[index] = rotateRight(sticker[index]);
	}
}

int CountSticker()
{
	int cnt = 0;
	for (int x = 0; x < N; x++)
		for (int y = 0; y < M; y++)
			cnt += notebook[x][y];
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
		sticker[i].assign(R, vector<int>(C));
		for (int x = 0; x < R; x++)
			for (int y = 0; y < C; y++)
				cin >> sticker[i][x][y];

		IsAttached(i);
	}

	cout << CountSticker();
}