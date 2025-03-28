#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
using namespace std;

int N, M;
int answer[1000][1000], map[1000][1000], group[1000][1000];
bool visited[1000][1000];
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
vector<int> group_size; // group_number - 1 부터 시작
int group_number = 1;

void BFS(int sy, int sx)
{
	queue<pair<int, int>> q;

	q.push({ sy, sx });
	visited[sy][sx] = true;
	group[sy][sx] = group_number;
	int count = 1;

	while (!q.empty())
	{
		auto [y, x] = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (visited[ny][nx] || map[ny][nx] == 1) continue;

			q.push({ ny, nx });
			visited[ny][nx] = true;
			count++;
			group[ny][nx] = group_number;
		}
	}
	
	group_size.push_back(count);
	group_number++;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;

	for (int y = 0; y < N; y++)
	{
		string input;
		cin >> input;
		for (int x = 0; x < M; x++)
		{
			map[y][x] = input[x] - '0';
		}
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (map[y][x] == 0 && group[y][x] == 0)
				BFS(y, x);
		}
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (map[y][x] == 1)
			{
				unordered_set<int> visited_group;
				answer[y][x] = 1;

				for (int i = 0; i < 4; i++)
				{
					int ny = y + dy[i];
					int nx = x + dx[i];

					if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
					if (map[ny][nx] == 0 && visited_group.find(group[ny][nx]) == visited_group.end())
					{
						answer[y][x] += group_size[group[ny][nx] - 1];
						visited_group.insert(group[ny][nx]);
					}
				}
			}
		}
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cout << (answer[y][x] % 10);
		}
		cout << endl;
	}

	return 0;
}