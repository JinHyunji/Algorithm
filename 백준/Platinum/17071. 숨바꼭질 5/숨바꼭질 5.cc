#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 500000

int N, K;
bool visited[2][MAX + 1] = { false }; // 짝수, 홀수 시간 배열로 방문 관리

int main()
{
	cin >> N >> K;

	queue<int> q;
	q.push(N); // 수빈이의 위치
	visited[0][N] = true;

	int t = 0;
	while (!q.empty())
	{
		int sister = K + t * (t + 1) / 2; // t초 후 동생의 위치

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

		int size = q.size();
		for (int i = 0; i < size; ++i)
		{
			int cur = q.front(); q.pop();

			for (int next : { cur - 1, cur + 1, cur * 2 })
			{
				if (next < 0 || next > MAX) continue;
				if (visited[(t + 1) % 2][next]) continue;

				visited[(t + 1) % 2][next] = true;
				q.push(next);
			}
		}

		t++;
	}
}