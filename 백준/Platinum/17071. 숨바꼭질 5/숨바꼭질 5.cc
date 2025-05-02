#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 500000

int N, K;
bool visited[2][MAX + 1] = { false };

int main()
{
	cin >> N >> K;

	queue<int> q;
	q.emplace(N);
	visited[0][N] = true;

	int t = 0;
	while (!q.empty())
	{
		int sister = K + t * (t + 1) / 2;
		
		if (sister > MAX)
		{
			cout << -1;
			return 0;
		}

		if (visited[t % 2][sister])
		{
			cout << t;
			return 0;
		}

		int qSize = q.size();
		for (int i = 0; i < qSize; i++)
		{
			int cur = q.front(); q.pop();

			for (int next : {cur + 1, cur - 1, cur * 2})
			{
				if (next < 0 || next > MAX) continue;
				if (visited[(t + 1) % 2][next]) continue;

				visited[(t + 1) % 2][next] = true;
				q.emplace(next);
			}
		}

		t++;
	}

	return 0;
}