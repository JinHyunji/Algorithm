#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <tuple>
using namespace std;

int N, M, P;
int map[1000][1000] = { 0, };
int movingCnts[10]; // 플레이어마다 이동 가능한 칸 수
vector<queue<pair<int, int>>> castles; // 플레이어 별 성의 위치
vector<int> answer; // 플레이어 별 성의 개수
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

bool end()
{
	for (int i = 1; i <= P; i++)
		if (castles[i].size() != 0) return false;

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> P;
	castles.resize(P + 1);
	answer.resize(P + 1);

	for (int i = 1; i <= P; i++)
		cin >> movingCnts[i];

	for (int y = 0; y < N; y++)
	{
		string str;
		cin >> str;

		for (int x = 0; x < M; x++)
		{
			if (str[x] != '.' && str[x] != '#')
			{
				map[y][x] = str[x] - '0';
				castles[map[y][x]].push({ y, x });
				answer[map[y][x]]++;
			}
			else if (str[x] == '#')
			{
				map[y][x] = -1;
			}
		}
	}

	while (!end())
	{
		for (int p = 1; p <= P; p++)
		{
			queue<pair<int, int>>& q = castles[p];
			int moveCount = movingCnts[p];

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

						map[ny][nx] = p;
						q.push({ ny, nx });
						answer[p]++;
					}
				}
			}
		}
	}

	for (int i = 1; i <= P; i++)
	{
		cout << answer[i] << " ";
	}

	return 0;
}