#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>
using namespace std;

int M, N, K, areaCnt = 0, tempArea;
vector<int> areas;
bool map[100][100];
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

void DFS(int x, int y)
{
	map[y][x] = true;
	tempArea++;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= M || nx >= N) continue;
		if (map[ny][nx]) continue;

		DFS(nx, ny);
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> M >> N >> K;

	for (int i = 0; i < K; i++)
	{
		int lbx, lby, rtx, rty;
		cin >> lbx >> lby >> rtx >> rty;
		lby = abs(lby + 1 - M);
		rtx = rtx - 1;
		rty = abs(rty - M);
		for (int y = rty; y <= lby; y++)
			for(int x = lbx; x <= rtx; x++)
				map[y][x] = true;
	}

	for (int y = 0; y < M; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (!map[y][x])
			{
				tempArea = 0;
				DFS(x, y);
				areaCnt++;
				areas.push_back(tempArea);
			}
		}
	}

	cout << areaCnt << endl;
	sort(areas.begin(), areas.end());
	for (const int& area : areas)
		cout << area << " ";

	return 0;
}