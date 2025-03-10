#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <string>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, count = 1;
	cin >> N;

	priority_queue pq([](pair<int, int> a, pair<int, int> b) {
		if (a.second == b.second) return a.first > b.first;
		return a.second > b.second;
		}, vector<pair<int,int>>());

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		pq.push(make_pair(a, b));
	}

	pair<int, int> cur = pq.top(); pq.pop();
	for (int i = 1; i < N; i++)
	{
		pair<int, int> top = pq.top();
		if (top.first < cur.second) pq.pop();
		else
		{
			pq.pop();
			cur = top;
			count++;
		}
	}

	cout << count;

	return 0;
}