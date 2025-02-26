#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, X;
	string output;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> pq; // 최소힙
	for (int i = 0; i < N; i++)
	{
		cin >> X;
		if (X == 0)
		{
			if (pq.empty())
			{
				output += "0\n";
				continue;
			}
			output += to_string(pq.top()) + "\n"; 
			pq.pop();
		}
		else
		{
			pq.push(X);
		}
	}

	cout << output;
}