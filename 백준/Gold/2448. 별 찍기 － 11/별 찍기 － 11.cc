#include <iostream>
using namespace std;

char board[10000][10000];

void fillStart(int x, int y)
{
	board[x][y] = board[x + 1][y - 1] = board[x + 1][y + 1] = '*';
	for (int i = y - 2; i <= y + 2; i++)
		board[x + 2][i] = '*';
}

void func(int x, int y, int n)
{
	if (n == 3)
	{
		fillStart(x, y);
		return;
	}
	else if (n < 3) return;

	int half = n / 2;
	func(x, y, half);
	func(x + half, y - half, half);
	func(x + half, y + half, half);
}

int main()
{
	int n;
	cin >> n;

	fill(&board[0][0], &board[9999][10000], ' ');

	int ny = (2 * n - 1) / 2;
	func(0, ny, n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2 * n - 1; j++)
			cout << board[i][j];
		cout << '\n';
	}
}