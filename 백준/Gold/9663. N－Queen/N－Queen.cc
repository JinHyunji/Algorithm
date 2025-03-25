#include <iostream>
using namespace std;

int N, answer = 0;
int col[15];

bool IsOk(int row)
{
	for (int prev = 0; prev < row; prev++)
	{
		if (col[prev] == col[row] || abs(col[row] - col[prev]) == abs(row - prev)) 
			return false;
	}
	return true;
}

void Backtracking(int row)
{
	if (row == N)
	{
		answer++;
		return;
	}

	for (int c = 0; c < N; c++)
	{
		col[row] = c;
		if (IsOk(row))
			Backtracking(row + 1);
	}
}

int main()
{
	cin >> N;
	Backtracking(0);
	cout << answer;
	return 0;
}