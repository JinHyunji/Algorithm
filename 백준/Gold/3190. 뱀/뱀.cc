#include <iostream>
#include <deque>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int N, K, L, second = 0, dir = 0; // 현재 방향
int board[110][110];
bool pos[110][110];
priority_queue<pair<int,char>, vector<pair<int,char>>, greater<pair<int,char>>> dirInfo; // 시간 오름차순 정렬

// 동 남 서 북
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;

	for (int i = 0; i < K; i++)
	{
		int r, c;
		cin >> r >> c;
		board[r - 1][c - 1] = 1; // 사과의 위치
	}

	cin >> L;
	for (int i = 0; i < L; i++)
	{
		int x; char c;
		cin >> x >> c;
		dirInfo.emplace(x, c);
	}

	deque<pair<int, int>> snake; // x, y
	snake.emplace_back(0, 0);
	pos[0][0] = true;

	while (true)
	{
		second++;

		auto [x, y] = snake.front();

		if (!dirInfo.empty() && second == dirInfo.top().first + 1)
		{
			char c = dirInfo.top().second; dirInfo.pop();
			if (c == 'D') // 오른쪽 90도 회전
			{
				dir = (dir + 1) % 4;
			}
			else // 왼쪽 90도 회전
			{
				dir = (dir + 3) % 4;
			}
		}

		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (pos[nx][ny] || nx < 0 || ny < 0 || nx == N || ny == N) // 자기 몸이랑 부딪히거나 벽이면 종료
		{
			cout << second;
			return 0;
		}

		snake.emplace_front(nx, ny);
		pos[nx][ny] = true;

		if (board[nx][ny] == 1) // 사과가 있다면
		{
			board[nx][ny] = 0;
		}
		else // 없다면
		{
			auto [tx, ty] = snake.back();
			snake.pop_back();
			pos[tx][ty] = false;
		}
	}
}