#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	int cost[3];
	int house[1000][3]{ 0 };

	for (int i = 1; i <= N; i++)
	{
		cin >> cost[0] >> cost[1] >> cost[2];
		house[i][0] = cost[0] + min(house[i - 1][1], house[i - 1][2]);
		house[i][1] = cost[1] + min(house[i - 1][0], house[i - 1][2]);
		house[i][2] = cost[2] + min(house[i - 1][0], house[i - 1][1]);
	}

	cout << min(house[N][0], min(house[N][1], house[N][2]));
	return 0;
}