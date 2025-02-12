#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

bool cmp(pair<int, int>& p1, pair<int, int>& p2)
{
	if (p1.second < p2.second)
	{
		return true;
	}
	else if (p1.second == p2.second)
	{
		return p1.first > p2.first;
	}
	else
	{
		return false;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, K;
	long long sum = 0;
	int answer = -1;
	cin >> N >> M >> K;
	priority_queue<int, vector<int>, greater<int>> pq;
	pair<int, int>* arr = new pair<int, int>[K];
	for (int i = 0; i < K; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + K, cmp);
	for (int i = 0; i < N; i++)
	{
		pq.push(arr[i].first);
		sum += arr[i].first;
	}
	if (sum >= M)
	{
		cout << arr[N-1].second;
	}
	else
	{
		for (int i = N; i < K; i++)
		{
			if (pq.top() < arr[i].first)
			{
				pq.push(arr[i].first);
				sum += ((long long)arr[i].first - (long long)pq.top());
				pq.pop();
				if (sum >= M)
				{
					answer = arr[i].second;
					break;
				}
			}
		}
		cout << answer << "\n";
	}
	return 0;
}