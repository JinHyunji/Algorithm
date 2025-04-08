#include <iostream>
#include <queue>
#include <string>
#include <tuple>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int L, R, C;
	const int dz[] = { 1, -1, 0, 0, 0, 0 };
	const int dy[] = { 0, 0, 1, -1, 0, 0 };
	const int dx[] = { 0, 0, 0, 0, 1, -1 };

	while (true)
	{
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) break;

		char map[30][30][30];
		tuple<int, int, int> S;

		// 입력 및 저장
		for (int z = 0; z < L; z++)
		{
			for (int y = 0; y < R; y++)
			{
				string input;
				cin >> input;
				for (int x = 0; x < C; x++)
				{
					map[z][y][x] = input[x];
					if (input[x] == 'S') S = { z, y, x };
				}
			}
			cin;
		}

		// BFS 탐색
		bool visited[30][30][30] = { false };
		queue<tuple<int, int, int, int>> q;

		q.push({get<0>(S), get<1>(S), get<2>(S), 0 }); // z, y, x, dist
		visited[get<0>(S)][get<1>(S)][get<2>(S)] = true;

		bool isFound = false;

		while (!q.empty())
		{
			auto [z, y, x, dist] = q.front(); 
			q.pop();

			if (map[z][y][x] == 'E')
			{
				// 출력
				isFound = true;
				cout << "Escaped in " << dist << " minute(s)." << endl;
				break;
			}

			for (int i = 0; i < 6; i++)
			{
				int nz = z + dz[i];
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (nz < 0 || ny < 0 || nx < 0 || nz >= L || ny >= R || nx >= C) continue;
				if (visited[nz][ny][nx] || map[nz][ny][nx] == '#') continue;

				q.push({ nz, ny, nx, dist + 1 });
				visited[nz][ny][nx] = true;
			}
			
		}

		if (isFound) continue;

		cout << "Trapped!" << endl;
	}
}