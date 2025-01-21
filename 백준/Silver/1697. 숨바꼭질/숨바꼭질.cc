#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main()
{
	int N, K;
	vector<bool> visited(100001, false);

	cin >> N >> K;

	if (N == K)
	{
		cout << 0;
		return 0;
	}

	queue<pair<int, int>> q;
	q.push({ N, 0 });
	visited[N] = true;

	while (!q.empty())
	{
		pair<int, int> node = q.front();
		q.pop();
		int pos = node.first;
		int cnt = node.second;

		if (pos == K)
		{
			cout << cnt;
			return 0;
		}

		int next;
		for (int i = 0;i < 3; i++)
		{
			if (i == 0)
			{
				next = pos - 1;
			} 
			else if (i == 1)
			{
				next = pos + 1;
			}
			else
			{
				next = pos * 2;
			}

			if (!visited[next] && next <= 100000 && next >= 0)
			{
				q.push({ next, cnt + 1 });
				visited[next] = true;
			}
		}
	}

	return 0;
}