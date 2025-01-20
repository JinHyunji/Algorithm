#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// DFS, BFS 함수 프로토타입
void DFS(int node);
void BFS(int node);

// 전역 변수로 선언
int N, M, V;
vector<vector<int>> arr;
vector<bool> visited;
string output;

int main()
{
	cin >> N >> M >> V;

	// 2차원 벡터 크기 설정
	arr.resize(N + 1, vector<int>(N + 1, 0)); // 기본값 0으로 초기화
	visited.resize(N + 1, false); // false로 초기화

	for (int i = 0; i < M; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;

		// 양방향 연결 표시
		arr[n1][n2] = 1;
		arr[n2][n1] = 1;
	}

	DFS(V);

	output += "\n"; // 출력 줄바꿈
	visited.assign(N + 1, false); // 사용한 visited 벡터 초기화

	BFS(V);

	cout << output;
}

void DFS(int node)
{
	visited[node] = true;
	output += to_string(node) + " ";


	for (int i = 1; i <= N; i++)
	{
		if (arr[node][i] == 1 && !visited[i]) DFS(i);
	}
}

void BFS(int node)
{
	queue<int> q;
	q.push(node);
	visited[node] = true;

	while (!q.empty())
	{
		node = q.front();
		q.pop();
		output += to_string(node) + " ";

		for (int i = 1; i <= N;i++)
		{
			if (arr[node][i] == 1 && !visited[i])
			{
				q.push(i);
				visited[i] = true;
			}
		}
	}
}