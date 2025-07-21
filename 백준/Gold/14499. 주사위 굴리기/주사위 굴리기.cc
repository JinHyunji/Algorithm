#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int N, M, X, Y, K;
int map[30][30];
int dice[7]; // 위, 뒤, 동, 서, 앞, 아래
int dx[] = { 0, 0, -1, 1 }; // 동, 서, 북, 남
int dy[] = { 1, -1, 0, 0 };

void Rotate(int dir)
{
	int temp[7];
	switch (dir)
	{
	case 1:
		temp[1] = dice[4];
		temp[2] = dice[2];
		temp[3] = dice[1];
		temp[4] = dice[6];
		temp[5] = dice[5];
		temp[6] = dice[3];
		break;
	case 2:
		temp[1] = dice[3];
		temp[2] = dice[2];
		temp[3] = dice[6];
		temp[4] = dice[1];
		temp[5] = dice[5];
		temp[6] = dice[4];
		break;
	case 3:
		temp[1] = dice[5];
		temp[2] = dice[1];
		temp[3] = dice[3];
		temp[4] = dice[4];
		temp[5] = dice[6];
		temp[6] = dice[2];
		break;
	case 4:
		temp[1] = dice[2];
		temp[2] = dice[6];
		temp[3] = dice[3];
		temp[4] = dice[4];
		temp[5] = dice[1];
		temp[6] = dice[5];
		break;
	}
	copy(begin(temp), end(temp), dice);
}

void Dice(int dir)
{
	int nx = X, ny = Y;
	nx += dx[dir - 1];
	ny += dy[dir - 1];

	if (nx < 0 || ny < 0 || nx >= N || ny >= M) return; // 지도 바깥이면 명령 무시

	// 주사위 이동
	Rotate(dir);

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