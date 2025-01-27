#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int N, M, answer;
vector<vector<int>> map; // 전체 지도 저장
vector<pair<int, int>> chickens; // 치킨집 위치 저장
vector<pair<int, int>> home; // 집 위치 저장
vector<pair<int, int>> picked; // 고른 치킨집 위치 저장

void Pick(int idx, int sIdx);
void Chicken(vector<pair<int, int>>& chicken);
int Dist(pair<int, int>& pos1, pair<int, int>& pos2);

int main()
{
	// 입출력 성능 향상
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 입력
	cin >> N >> M;
	answer = INT_MAX;
	map.resize(N, vector<int>(N));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			
			if (map[i][j] == 2) chickens.push_back({ i, j }); // 치킨집 위치 저장
			else if (map[i][j] == 1) home.push_back({ i, j }); // 집 위치 저장
		}
	}

	picked.resize(M);

	// M개의 치킨집 고르기
	Pick(0, 0);

	// 출력
	cout << answer;
}

void Pick(int idx, int sIdx)
{
	// 다 골랐으면
	if (sIdx == M)
	{
		// 도시의 치킨 거리 구하기
		Chicken(picked);
		return;
	}

	if (idx == chickens.size()) return;

	picked[sIdx] = chickens[idx]; // 고른 치킨집 담기
	Pick(idx + 1, sIdx + 1); // 다음 요소 담기
	Pick(idx + 1, sIdx); // 다음 요소 안 담기
}

void Chicken(vector<pair<int, int>>& chicken)
{
	int sum = 0;
	for (int i = 0; i < home.size(); i++)
	{
		int minChicken = INT_MAX;
		for (int j = 0; j < chicken.size(); j++)
		{
			minChicken = min(minChicken, Dist(home[i], chicken[j])); // 치킨 거리의 최소값 구하기
		}
		sum += minChicken; // 도시의 치킨 거리 구하기
	}

	answer = min(sum, answer); // 도시의 치킨 거리의 최소값 구하기
}

int Dist(pair<int, int>& pos1, pair<int, int>& pos2)
{
	return abs(pos1.first - pos2.first) + abs(pos1.second - pos2.second);
}