#include <iostream>
using namespace std;

const int MAX = 2190;
char board[MAX][MAX];

void func(int n, int x, int y)
{
	if (n == 1)
	{
		board[x][y] = '*';
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == 1 && j == 1) continue;
			func(n / 3, x + n / 3 * i, y + n / 3 * j);
		}
	}
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		fill(board[i], board[i] + n, ' ');

	func(n, 0, 0);
	for (int i = 0; i < n; i++)
		cout << board[i] << '\n';
}