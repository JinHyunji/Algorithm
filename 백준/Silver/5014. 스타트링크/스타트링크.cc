#include <iostream>
#include <queue>
using namespace std;

int F, S, G, U, D;
bool visited[1000001] = { false };

void BFS()
{
	queue<pair<int, int>> q;
	q.push({ S, 0 }); // 강호의 위치, 버튼을 누른 횟수
	visited[S] = true;

	while (!q.empty())
	{
		auto [pos, button] = q.front();
		q.pop();

		if (pos == G)
		{
			cout << button;
			return;
		}

		// 위로 올라가기
		{
			int nextPos = pos + U;
			if (nextPos <= F && !visited[nextPos]) // 최고층보다 높지 않고 방문한 적이 없으면
			{
				q.push({ nextPos, button + 1 });
				visited[nextPos] = true;
			}
		}

		// 아래로 내려가기
		{
			int nextPos = pos - D;
			if (nextPos > 0 && !visited[nextPos]) // 1층보다 낮지 않고 방문한 적이 없으면
			{
				q.push({ nextPos, button + 1 });
				visited[nextPos] = true;
			}
		}
	}

	cout << "use the stairs";
	return;
}

int main()
{
	cin >> F >> S >> G >> U >> D;
	BFS();
}