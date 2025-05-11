#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	int Y = 0, M = 0;
	for (int i = 0; i < N; i++)
	{
		int chg;
		cin >> chg;

		Y += 10 * (chg / 30 + 1);
		M += 15 * (chg / 60 + 1);
	}

	if (Y < M)
	{
		cout << "Y " << Y;
	}
	else if (Y > M)
	{
		cout << "M " << M;
	}
	else
	{
		cout << "Y M " << Y;
	}
}