#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, times = 0, eatenFishes = 0, sharkSize = 2;
int map[20][20];
pair<int, int> babyShark;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

vector<pair<int, int>> CountFishes()
{
	vector<pair<int, int>> fishes;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			if (map[y][x] > 0 && map[y][x] < sharkSize)
				fishes.push_back({ y, x });
	return fishes;
}


// BFS로 수정
void EatToFish(int startY, int startX, int desY, int desX)
{
	queue<vector<int>> q;
	vector<vector<bool>> visited(N, vector<bool>(N, false));
	q.push({ startY, startX, 0 });
	visited[startY][startX] = true;

	while (!q.empty())
	{
		vector<int> fish = q.front(); q.pop();

		if (fish[0] == desY && fish[1] == desX)
		{
			eatenFishes++;
			map[desY][desX] = 0;
			babyShark = { desY, desX };
			times += fish[2];
			
			if (eatenFishes == sharkSize)
			{
				sharkSize++;
				eatenFishes = 0;
			}
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = fish[0] + dy[i];
			int nx = fish[1] + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx] || map[ny][nx] > sharkSize)
				continue;

			visited[ny][nx] = true;
			q.push({ ny, nx, fish[2] + 1 });
		}
	}

}


pair<int,int> FindClosetFishes(int y, int x, vector<pair<int,int>>& fishes)
{
	int minDist = INT32_MAX;
	pair<int, int> fishPos = { y, x };

	for (const auto& fish : fishes)
	{
		vector<vector<bool>> visited(N, vector<bool>(N, false));
		queue<vector<int>> q;
		q.push({ y, x, 0 });
		visited[y][x] = true;

		while (!q.empty())
		{
			vector<int> node = q.front(); q.pop();

			if (node[0] == fish.first && node[1] == fish.second)
			{
				if (minDist > node[2])
				{
					minDist = node[2];
					fishPos.first = node[0];
					fishPos.second = node[1];
				}
				else if (minDist == node[2])
				{
					minDist = node[2];
					if (fishPos.first > node[0])
					{
						fishPos.first = node[0];
						fishPos.second = node[1];
					}
					else if (fishPos.first == node[0])
					{
						if (fishPos.second > node[1])
						{
							fishPos.first = node[0];
							fishPos.second = node[1];
						}
					}
				}
			}

			for (int i = 0; i < 4; i++)
			{
				int ny = node[0] + dy[i];
				int nx = node[1] + dx[i];

				if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx] || map[ny][nx] > sharkSize)
					continue;

				q.push({ ny, nx, node[2] + 1 });
				visited[ny][nx] = true;
			}
		}
	}
	
	return fishPos;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> map[y][x];
			if (map[y][x] == 9) babyShark = { y, x }, map[y][x] = 0;
		}
	}

	while (true)
	{
		vector<pair<int,int>> fishes = CountFishes();
		if (fishes.empty()) break;

		pair<int,int> fish = FindClosetFishes(babyShark.first, babyShark.second, fishes);
		if (fish == babyShark) break;

		EatToFish(babyShark.first, babyShark.second, fish.first, fish.second);
	}

	cout << times;
	return 0;
}