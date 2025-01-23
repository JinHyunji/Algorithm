#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 100000;

int main()
{
	int N, K;
	cin >> N >> K;

	vector<bool> visited(MAX + 1);

	queue<pair<int, int>> q;
	q.push({ N, 0 });
	visited[N] = true;

	while (!q.empty())
	{
		int pos = q.front().first;
		int time = q.front().second;
		q.pop();

		if (pos == K)
		{
			cout << time;
			return 0;
		}

		for (int i = 0; i < 3; i++)
		{
			int next;
			if (i == 0)
			{
				next = pos * 2;
			}
			else if (i == 1)
			{
				next = pos - 1;
			}
			else
			{
				next = pos + 1;
			}

			if (next >= 0 && next <= MAX && !visited[next])
			{
				if (i == 0)
				{
					q.push({ next, time });
				}
				q.push({ next, time + 1 });
				visited[next] = true;
			}

		}
	}
}