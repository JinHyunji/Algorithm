#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int N, M, K;
vector<pair<int, int>> beers;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	// 입출력 성능 향상
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 입력
	cin >> N >> M >> K;
	beers.resize(K);

	for (int i = 0; i < K; i++)
	{
		cin >> beers[i].first >> beers[i].second;
	}

	// second를 기준으로 오름차순 정렬
	sort(beers.begin(), beers.end(), [](pair<int, int>& a, pair<int, int>& b)
		{
			return a.second < b.second;
		});

	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += beers[i].first;
		pq.push(beers[i].first);
	}

	if (sum >= M)
	{
		cout << beers[N - 1].second;
	}
	else
	{
		for (int i = N; i < K; i++)
		{
			if (pq.top() < beers[i].first)
			{
				sum += beers[i].first - pq.top(); pq.pop();
				pq.push(beers[i].first);

				if (sum >= M)
				{
					cout << beers[i].second;
					return 0;
				}
			}
		}

		cout << -1;
	}

	return 0;
}