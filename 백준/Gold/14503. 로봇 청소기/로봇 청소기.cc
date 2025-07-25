#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

int N, M, R, C, D;
int room[60][60];

// 북, 동, 남, 서 (4방향 탐색 시 사용)
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

// 북, 동, 남, 서 방향의 뒤쪽 칸
int bx[] = { 1, 0, -1, 0 };
int by[] = { 0, -1, 0, 1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> R >> C >> D;
	for (int x = 0; x < N; x++)
		for (int y = 0; y < M; y++)
			cin >> room[x][y];

	int answer = 0;
	while (true)
	{
		// 현재 칸이 청소되지 않은 경우 청소한다.
		if (room[R][C] == 0) room[R][C] = 2;

		int cleaned = 0;
		for (int i = 0; i < 4; i++)
		{
			int nx = R + dx[i];
			int ny = C + dy[i];

			if (room[nx][ny] != 0)
				cleaned++;
		}

		if (cleaned == 4) // 현재 칸의 주변 칸이 모두 청소된 경우
		{
			int nx = R + bx[D];
			int ny = C + by[D];

			if (room[nx][ny] == 1) // 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
			{
				for (int x = 0; x < N; x++)
					for (int y = 0; y < M; y++)
						if (room[x][y] == 2) answer++;

				cout << answer;
				return 0;
			}
			else // 한 칸 후진이 된다면 후진하고 1번으로 돌아간다.
			{
				R = nx;
				C = ny;
				continue;
			}
		}
		else // 현재 칸 주변 칸이 모두 청소되지 않은 경우
		{
			// 반시계 90도 회전
			D = (D + 3) % 4;

			// 바라보는 방향의 앞쪽 칸이 빈칸이면 한칸 전진 후 1번으로 돌아간다.
			int nx = R + dx[D];
			int ny = C + dy[D];

			if (room[nx][ny] != 0) // 갈 수 없는 곳이면 정지 후 1번으로 돌아간다.
				continue;

			R = nx;
			C = ny;
		}
	}
}