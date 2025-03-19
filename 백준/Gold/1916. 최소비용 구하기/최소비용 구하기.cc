#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cstdint>
#include <algorithm>
using namespace std;
using ll = long long;

int N, M, startC, endC;
vector<pair<int, int>> graph[1001];
int dist[1001];
bool visited[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	// 입력
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		graph[start].push_back(make_pair(end, cost));
	}

	cin >> startC >> endC;

	fill(dist, dist + 1001, 1e9);  // dist 배열을 충분히 큰 값(무한대)으로 설정

	// 최소 비용 탐색 : 다익스트라
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // 최소 힙으로 변경
	
	dist[startC] = 0;
	pq.push({ 0, startC });

	while (!pq.empty())
	{
		int currCost = pq.top().first, currCity = pq.top().second; pq.pop();

		if (visited[currCity]) continue; // 이미 방문한 도시면 건너뛰기
		visited[currCity] = true; // 방문 처리

		if (currCity == endC) break; // 목표 지점에 도착하면 탐색 종료

		for (auto next : graph[currCity])
		{
			int nextCity = next.first, cost = next.second;
			if (dist[nextCity] > currCost + cost) // 해당 도시까지 거리와 현재 도시까지 총 비용 비교
			{
				dist[nextCity] = currCost + cost;
				pq.push({ dist[nextCity], nextCity });
			}
		}
	}

	// 출력
	cout << dist[endC];
	return 0;
}