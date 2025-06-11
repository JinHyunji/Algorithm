#include <iostream>
#include <string>
using namespace std;

// ========== Variables ==========
const int MAX = 64;
int N;
int paper[MAX][MAX];
string output;
// ===============================

bool check(int x, int y, int n)
{
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
			if (paper[x][y] != paper[i][j]) return false;
	return true;
}

void solve(int x, int y, int z)
{
	if (check(x, y, z))
	{
		output += paper[x][y];
		return;
	}

	output += '(';
	int n = z / 2;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			solve(x + n * i, y + n * j, n);
		}
	}
	output += ')';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int x = 0; x < N; x++)
	{
		string input;
		cin >> input;
		for (int y = 0; y < N; y++)
			paper[x][y] = input[y];
	}

	solve(0, 0, N);
	cout << output;
}