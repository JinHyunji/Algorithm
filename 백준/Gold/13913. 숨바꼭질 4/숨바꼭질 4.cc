#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100000;

int main()
{
	int N, K;
	cin >> N >> K;

	vector<int> visited(MAX + 1, -1);
	queue<int> q;
	
	q.push(N); // 현재 위치와 탐색 시간
	visited[N] = -2;

	vector<int> path;

	while (!q.empty())
	{
		int curr = q.front(); q.pop();

		if (curr == K)
		{
			for (int pos = K; pos != -2; pos = visited[pos])
			{
				path.push_back(pos);
			}

			break;
		}

		for (int next : {curr - 1, curr + 1, curr * 2})
		{
			if (next >= 0 && next <= MAX && visited[next] == -1)
			{
				q.push(next);
				visited[next] = curr;
			}
		}
	}

	reverse(path.begin(), path.end());

	cout << path.size() - 1 << endl;
	for (int pos : path)
	{
		cout << pos << " ";
	}

	return 0;
}