#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <unordered_map>
using namespace std;

int N, M;
unordered_map<int, int> info;
bool visited[101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		info[a] = b;
	}

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		info[a] = b;
	}

	queue<pair<int,int>> q;
	visited[1] = true;
	q.push({ 1, 0 });

	while (!q.empty())
	{
		auto [pos, dice] = q.front();
		q.pop();

		if (pos == 100)
		{
			cout << dice;
			return 0;
		}

		// 주사위 범위 내에서 이동 (1에서 6까지)
		for (int i = 1; i < 7; i++)
		{
			int nPos = pos + i;

			if (nPos > 100 || visited[nPos]) continue;

			// 사다리 또는 뱀이 있는 칸이면, 해당 칸이 가리키는 곳으로 이동
			if (info.find(nPos) != info.end())
			{
				nPos = info[nPos]; // 이동 위치 변경
			}

			if (!visited[nPos])
			{
				visited[nPos] = true;
				q.push({ nPos, dice + 1 });
			}
		}
	}
	
	return 0;
}