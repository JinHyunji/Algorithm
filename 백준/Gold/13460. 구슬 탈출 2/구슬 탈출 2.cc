#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
pair<int, int> R, B, O;
char board[10][10];
bool visited[10][10][10][10];
bool IsOut = false;
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

struct State
{
	int ry, rx, by, bx, moves;
};

// 구슬을 이동시키는 함수
void move(int& y, int& x, int& count, int& i)
{
	while (board[y + dy[i]][x + dx[i]] != '#' && board[y][x] != 'O')
	{
		y += dy[i];
		x += dx[i];
		count++;
	}
}

int BFS()
{
	queue<State> q;
	q.push({ R.first, R.second, B.first, B.second, 0 });
	visited[R.first][R.second][B.first][B.second] = true;

	while (!q.empty())
	{
		State cur = q.front(); q.pop();

		if (cur.moves >= 10) break;

		for (int i = 0; i < 4; i++)
		{
			int nrx = cur.rx, nry = cur.ry, rc = 0;
			int nbx = cur.bx, nby = cur.by, bc = 0;

			move(nry, nrx, rc, i);
			move(nby, nbx, bc, i);

			// 파란 구슬이 구멍에 빠지면 실패
			if (board[nby][nbx] == 'O') continue;

			// 빨간 구슬만 구멍에 빠지면 정답
			if (board[nry][nrx] == 'O') return cur.moves + 1;

			// 두 구슬이 같은 위치에 있으면 이동 거리를 비교해 조정
			if (nrx == nbx && nry == nby)
			{
				if (rc > bc) // 빨간 구슬이 더 많이 이동했으면 한 칸 뒤로
				{
					nrx -= dx[i];
					nry -= dy[i];
				}
				else // 파란 구슬이 더 많이 이동했으면 한 칸 뒤로
				{
					nbx -= dx[i];
					nby -= dy[i];
				}
			}

			if (visited[nry][nrx][nby][nbx]) continue;

			visited[nry][nrx][nby][nbx] = true;
			q.push({ nry, nrx, nby, nbx, cur.moves + 1 });
		}
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
		{
			cin >> board[y][x];
			if (board[y][x] == 'O') O = { y, x };
			else if (board[y][x] == 'R') R = { y, x };
			else if (board[y][x] == 'B') B = { y, x };
		}

	cout << BFS();
	return 0;
}