#include <iostream>
using namespace std;

const int Max = 2190;
int N;
int map[Max][Max];
int cnt[3];

bool check(int x, int y, int n)
{
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
			if (map[i][j] != map[x][y])
				return false;
	return true;
}

void solve(int x, int y, int z)
{
	if (check(x, y, z))
	{
		cnt[map[x][y] + 1]++;
		return;
	}

	int n = z / 3;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			solve(x + i * n, y + j * n, n);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int x = 0; x < N; x++)
		for (int y = 0; y < N; y++)
			cin >> map[x][y];

	solve(0, 0, N);

	for (int c : cnt) cout << c << '\n';
}