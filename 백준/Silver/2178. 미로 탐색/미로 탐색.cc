#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	// 입출력 성능 향상
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 입력
	int N, M;
	cin >> N >> M;

	vector<vector<int>> map(N, vector<int>(M));

	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;

		for (int j = 0; j < M; j++)
		{
			map[i][j] = input[j] - '0';
		}
	}

	// 로직
	// BFS 탐색 -> 위치와 이동한 칸 수 저장(인덱스 0,0 부터 N-1, M-1까지)
	//	-> 위치가 도착 위치면 -> 이동한 칸 수 출력 후 탐색 종료
	//	-> 도착 위치가 아니면 -> 사방 탐색 후 위치와 이동한 칸 수 저장
	// 큐가 빌 때까지 위의 내용 반복

	vector<vector<bool>> visited(N, vector<bool>(M));
	queue<vector<int>> q;

	// 사방 탐색을 위한 델타 배열 사용
	int dy[]{ -1, 1, 0, 0 };
	int dx[]{ 0, 0, -1, 1 };

	q.push({ 0, 0, 1 });
	visited[0][0] = true;

	while (!q.empty())
	{
		int y = q.front()[0];
		int x = q.front()[1];
		int cnt = q.front()[2];
		q.pop();

		if (y == N - 1 && x == M - 1)
		{
			// 출력
			cout << cnt;
			return 0;
		}

		for (int i = 0;i < 4;i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= 0 && ny < N && nx >= 0 && nx < M && map[ny][nx] == 1 && !visited[ny][nx])
			{
				visited[ny][nx] = true;
				q.push({ ny, nx, cnt + 1 });
			}
		}
	}
}