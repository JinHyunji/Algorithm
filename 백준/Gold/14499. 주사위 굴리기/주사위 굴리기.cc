#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int N, M, X, Y, K;
int map[30][30];
int dice[7]; // 위, 뒤, 동, 서, 앞, 아래

void Dice(int dir)
{
	if (dir == 1) // 동
	{
		int nx = X;
		int ny = Y + 1;

		if (nx < 0 || ny < 0 || nx >= N || ny >= M) return; // 지도 바깥이면 명령 무시

		// 주사위 이동
		int temp[7];
		temp[1] = dice[4];
		temp[2] = dice[2];
		temp[3] = dice[1];
		temp[4] = dice[6];
		temp[5] = dice[5];
		temp[6] = dice[3];

		copy(begin(temp), end(temp), dice);

		if (map[nx][ny] == 0)
		{
			map[nx][ny] = dice[6];
		}
		else
		{
			dice[6] = map[nx][ny];
			map[nx][ny] = 0;
		}

		cout << dice[1] << '\n';
		X = nx, Y = ny;
		return;
	}
	else if (dir == 2) // 서
	{
		int nx = X;
		int ny = Y - 1;

		if (nx < 0 || ny < 0 || nx >= N || ny >= M) return; // 지도 바깥이면 명령 무시

		// 주사위 이동
		int temp[7];
		temp[1] = dice[3];
		temp[2] = dice[2];
		temp[3] = dice[6];
		temp[4] = dice[1];
		temp[5] = dice[5];
		temp[6] = dice[4];

		copy(begin(temp), end(temp), dice);

		if (map[nx][ny] == 0)
		{
			map[nx][ny] = dice[6];
		}
		else
		{
			dice[6] = map[nx][ny];
			map[nx][ny] = 0;
		}

		cout << dice[1] << '\n';
		X = nx, Y = ny;
		return;
	}
	else if (dir == 3) // 북
	{
		int nx = X - 1;
		int ny = Y;

		if (nx < 0 || ny < 0 || nx >= N || ny >= M) return; // 지도 바깥이면 명령 무시

		// 주사위 이동
		int temp[7];
		temp[1] = dice[5];
		temp[2] = dice[1];
		temp[3] = dice[3];
		temp[4] = dice[4];
		temp[5] = dice[6];
		temp[6] = dice[2];

		copy(begin(temp), end(temp), dice);

		if (map[nx][ny] == 0)
		{
			map[nx][ny] = dice[6];
		}
		else
		{
			dice[6] = map[nx][ny];
			map[nx][ny] = 0;
		}

		cout << dice[1] << '\n';
		X = nx, Y = ny;
		return;
	}
	else // 남
	{
		int nx = X + 1;
		int ny = Y;

		if (nx < 0 || ny < 0 || nx >= N || ny >= M) return; // 지도 바깥이면 명령 무시

		// 주사위 이동
		int temp[7];
		temp[1] = dice[2];
		temp[2] = dice[6];
		temp[3] = dice[3];
		temp[4] = dice[4];
		temp[5] = dice[1];
		temp[6] = dice[5];

		copy(begin(temp), end(temp), dice);

		if (map[nx][ny] == 0)
		{
			map[nx][ny] = dice[6];
		}
		else
		{
			dice[6] = map[nx][ny];
			map[nx][ny] = 0;
		}

		cout << dice[1] << '\n';
		X = nx, Y = ny;
		return;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> X >> Y >> K;
	for (int x = 0; x < N; x++)
		for (int y = 0; y < M; y++)
			cin >> map[x][y];

	int dir;
	for (int i = 0; i < K; i++)
	{
		cin >> dir;

		// 주사위 굴리기
		Dice(dir);
	}
}