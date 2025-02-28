#include <iostream>
#include <queue>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string output;
	int N, x;
	cin >> N;

	priority_queue pq([](pair<int, int> a, pair<int, int> b) { 
		if (a.first == b.first) return a.second > b.second;
		return a.first > b.first;
		}, vector<pair<int, int>>());

	for (int i = 0; i < N; i++)
	{
		cin >> x;

		if (x == 0)
		{
			if (pq.empty())
			{
				output += "0\n";
				continue;
			}
			output += to_string(pq.top().second) + "\n";
			pq.pop();
		}
		else
		{
			pq.push({ abs(x), x });
		}
	}

	cout << output;
}