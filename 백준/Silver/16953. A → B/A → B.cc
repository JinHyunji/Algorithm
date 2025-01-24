#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const long long MAX = 1000000000;

int main()
{
	long long A, B;
	cin >> A >> B;

	vector<bool> visited(MAX + 1, false);
	queue<pair<long long, int>> q;
	q.push({ A, 1 });
	visited[A] = true;

	while (!q.empty())
	{
		long long num = q.front().first;
		int op = q.front().second;
		q.pop();

		if (num == B)
		{
			cout << op;
			return 0;
		}

		for (long long i : {num * 2, num * 10 + 1})
		{
			if (i >= 1 && i <= MAX && !visited[i])
			{
				visited[i] = true;
				q.push({ i, op + 1 });
			}
		}
	}

	cout << -1;
	return 0;
}