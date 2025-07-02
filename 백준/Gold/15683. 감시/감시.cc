#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int map[10][10];
int tempMap[10][10];
int dx[] = { 0, 1, 0, -1 }; // 동 남 서 북
int dy[] = { 1, 0, -1, 0 };
vector<pair<int, int>> cctv;

bool OOB(int x, int y)
{
	return x < 0 || y < 0 || x >= N || y >= M;
}

void upd(int x, int y, int dir)
{
	dir %= 4;
	while (true)
	{
		x += dx[dir];
		y += dy[dir];
		if (OOB(x, y) || tempMap[x][y] == 6) return;
		if (tempMap[x][y] != 0) continue;
		tempMap[x][y] = 7;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int mn = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j] != 6)
				cctv.emplace_back(i, j);
			if (map[i][j] == 0)
				mn++;
		}
	}

	for (int temp = 0; temp < (1 << (2 * cctv.size())); temp++)
	{
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				tempMap[i][j] = map[i][j];

		int brute = temp;
		for (int i = 0; i < cctv.size(); i++)
		{
			int dir = brute % 4;
			brute /= 4;
			auto [x, y] = cctv[i];

			if (map[x][y] == 1)
			{
				upd(x, y, dir);
			}
			else if (map[x][y] == 2)
			{
				upd(x, y, dir);
				upd(x, y, dir + 2);
			}
			else if (map[x][y] == 3)
			{
				upd(x, y, dir);
				upd(x, y, dir + 1);
			}
			else if (map[x][y] == 4)
			{
				upd(x, y, dir);
				upd(x, y, dir+1);
				upd(x, y, dir+3);
			}
			else
			{
				upd(x, y, dir);
				upd(x, y, dir + 1);
				upd(x, y, dir + 2);
				upd(x, y, dir + 3);
			}
		}
		
		int val = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				val += (tempMap[i][j] == 0);
		mn = min(mn, val);
	}
	cout << mn;
}