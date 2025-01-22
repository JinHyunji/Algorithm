#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, answer, cnt;
vector<vector<int>> map, visited;
vector<int> answer_count;
int dx[]{ 0, 0, -1, 1 };
int dy[]{ -1, 1, 0, 0 };

void DFS(int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	map.resize(N, vector<int>(N, 0));
	visited.resize(N, vector<int>(N, 0));
	answer_count.resize(N * N, 0);

	string input;

	for (int i = 0;i < N; i++)
	{
		cin >> input;
		for (int j = 0; j < N;j++)
		{
			if (isdigit(input[j]))
			{
				map[i][j] = input[j] - '0';
			}
		}
	}

	for (int i = 0;i < N; i++)
	{
		for (int j = 0; j < N;j++)
		{
			if (visited[i][j] == 0 && map[i][j] == 1)
			{
				cnt = 0;
				DFS(j, i);
				answer_count[answer++] = cnt;
			}
		}
	}

	sort(answer_count.begin(), answer_count.end());
	cout << answer << endl;
	for (int cnt : answer_count)
	{
		if (cnt != 0) cout << cnt << endl;
	}
}


void DFS(int x, int y)
{
	visited[y][x] = 1;
	cnt++;

	for (int k = 0;k < 4;k++)
	{
		int nx = dx[k] + x;
		int ny = dy[k] + y;
		if (nx >= 0 && nx < N && ny >= 0 && ny < N && visited[ny][nx] == 0 && map[ny][nx] == 1)
		{
			DFS(nx, ny);
		}
	}
}