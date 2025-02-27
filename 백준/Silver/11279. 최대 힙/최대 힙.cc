#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, x;
	string output;
	cin >> N;

	priority_queue<int> pq;

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

			output += to_string(pq.top()) + "\n";
			pq.pop();
		}
		else
		{
			pq.push(x);
		}
	}

	cout << output;
}