#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

const static int MAX = 100;

// 위 아래 왼 오 앞 뒤
int dx[] = { 0, 0, -1, 1, 0, 0 }; // M
int dy[] = { 0, 0, 0, 0, 1, -1 }; // N
int dz[] = { 1, -1, 0, 0, 0, 0 }; // H

int M, N, H, days = 0;
int map[MAX][MAX][MAX];
queue<tuple<int, int, int, int>> q;

bool IsAllRipe()
{
	for (int h = 0; h < H; h++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[h][i][j] == 0)
				{
					return false;
				}
			}
		}
	}

	return true;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> M >> N >> H;
	for (int h = 0; h < H; h++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[h][i][j];

				if (map[h][i][j] == 1)
				{
					q.push({ j, i, h, 0 }); // x, y, z, day
				}
			}
		}
	}

	if (IsAllRipe()) // 모두 익으면 날짜 출력 후 종료
	{
		cout << days;
		return 0;
	}

	while (!q.empty())
	{
		auto [x, y, z, day] = q.front(); q.pop();

		for (int i = 0; i < 6; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			if (nx < 0 || ny < 0 || nz < 0 || nx >= M || ny >= N || nz >= H) continue;
			if (map[nz][ny][nx] != 0) continue; // 토마토가 없거나 이미 익어있으면 패스

			// 방문 처리 후 큐에 넣기
			map[nz][ny][nx] = 1;
			q.push({ nx, ny, nz, day + 1 });
		}

		if (q.empty())
		{
			days = day;
		}
	}
	
	if (IsAllRipe()) // 모두 익으면 날짜 출력 후 종료
	{
		cout << days;
	}
	else
	{
		cout << -1; // 모두 익지 못하면 -1 출력
	}

	return 0;
}