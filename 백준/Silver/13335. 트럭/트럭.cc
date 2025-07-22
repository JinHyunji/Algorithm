#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int N, W, L, T = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> W >> L;

	queue<int> truck;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		truck.push(n);
	}
	
	queue<int> bridge;
	for (int i = 0; i < W; i++)
		bridge.push(0);

	int sum = 0;
	while (!truck.empty() || sum > 0)
	{
		T++;

		if (bridge.front() != 0)
		{
			sum -= bridge.front();
		}
		bridge.pop();

		if (!truck.empty() && sum + truck.front() <= L)
		{
			bridge.push(truck.front());
			sum += truck.front(); 
			truck.pop();
		}
		else
		{
			bridge.push(0);
		}
	}

	cout << T;
}