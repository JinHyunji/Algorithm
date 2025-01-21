#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100000;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K, min_time, ways;
	cin >> N >> K;

	if (N == K)
	{
		cout << "0\n1\n";
		return 0;
	}

	vector<int> visited(MAX + 1, -1);
	queue<pair<int, int>> q;

	q.push({ N, 0 });
	visited[N] = 0;

	min_time = -1;
	ways = 0;

	while (!q.empty())
	{
		int pos = q.front().first;
		int time = q.front().second;
		q.pop();

		if (pos == K)
		{
			if (min_time == -1) min_time = time;
			if (time == min_time) ways++;
			continue;
		}

		for (int next : {pos - 1, pos + 1, pos * 2})
		{
			if (next < 0 || next > MAX) continue;
			if (visited[next] == -1 || visited[next] == time + 1)
			{
				q.push({ next, time + 1 });
				visited[next] = time + 1;
			}
		}
	}

	cout << min_time << "\n" << ways;
}