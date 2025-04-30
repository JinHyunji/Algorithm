#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int N, M, P;
int map[1000][1000] = { 0, };
int moveableCnt[10];
vector<queue<pair<int, int>>> playerPos;
vector<int> answer;
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

bool End()
{
	for (int i = 1; i <= P; i++)
		if (!playerPos[i].empty()) return false;

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> P;
	playerPos.resize(P + 1);
	answer.resize(P + 1);

	for (int i = 1; i <= P; i++)
		cin >> moveableCnt[i];

	for (int y = 0; y < N; y++)
	{
		string str;
		cin >> str;

		for (int x = 0; x < M; x++)
		{
			if (str[x] == '#')
			{
				map[y][x] = -1;
			}
			else if (str[x] != '.')
			{
				map[y][x] = str[x] - '0';
				playerPos[map[y][x]].push({ y, x });
				answer[map[y][x]]++;
			}
		}
	}

	while (!End())
	{
		for (int player = 1; player <= P; player++)
		{
			queue<pair<int, int>>& q = playerPos[player];
			int moveCount = moveableCnt[player];

			for (int step = 0; step < moveCount && !q.empty(); step++)
			{
				int qSize = q.size();

				while (qSize--)
				{
					auto [y, x] = q.front(); q.pop();

					for (int i = 0; i < 4; i++)
					{
						int ny = y + dy[i];
						int nx = x + dx[i];

						if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
						if (map[ny][nx] == -1 || map[ny][nx] != 0) continue;

						map[ny][nx] = player;
						q.push({ ny, nx });
						answer[player]++;
					}
				}
			}
		}
	}

	for (int i = 1; i <= P; i++)
		cout << answer[i] << " ";

	return 0;
}