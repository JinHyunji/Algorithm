#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define X first
#define Y second

int N, M, chickenCnt = 0, houseCnt = 0, answer = INT32_MAX;
int map[50][50];
vector<pair<int, int>> picked(13);
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;

int distance(pair<int, int> R, pair<int, int> C)
{
	return abs(R.X - C.X) + abs(R.Y - C.Y);
}

void func(int idx, int sIdx)
{
	if (sIdx == M)
	{
		int sum = 0;
		for (int i = 0; i < houseCnt; i++)
		{
			int mnDist = INT32_MAX;
			for (int j = 0; j < M; j++)
			{
				mnDist = min(mnDist, distance(houses[i], picked[j]));
			}
			sum += mnDist;
		}
		answer = min(answer, sum);
		return;
	}

	if (idx == chickenCnt) return;

	picked[sIdx] = chickens[idx];
	func(idx + 1, sIdx + 1);
	func(idx + 1, sIdx);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < N; y++)
		{
			cin >> map[x][y];
			if (map[x][y] == 1)
			{
				houses.emplace_back(x, y);
				houseCnt++;
			}
			if (map[x][y] == 2)
			{
				chickens.emplace_back(x, y);
				chickenCnt++;
			}
		}
	}

	func(0, 0);
	cout << answer;
}