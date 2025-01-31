#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 1000000;
int N, answer;
vector<int> dp(MAX + 1, -1); // 경로 저장
vector<int> visited(MAX + 1, -1); // 방문 여부 저장


int main()
{
	cin >> N;

	queue<pair<int, int>> q;
	q.push({ N, 0 });
	visited[N] = 0;

	while (!q.empty())
	{
		int num = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (num == 1)
		{
			answer = cnt;
			break;
		}

		if (num % 3 == 0 && visited[num / 3] == -1)
		{
			dp[num / 3] = num;
			visited[num / 3] = true;
			q.push({ num / 3, cnt + 1 });
		}
		if (num % 2 == 0 && visited[num / 2] == -1)
		{
			dp[num / 2] = num;
			visited[num / 2] = true;
			q.push({ num / 2, cnt + 1 });
		}

		if (visited[num - 1] == -1)
		{
			dp[num - 1] = num;
			visited[num - 1] = true;
			q.push({ num - 1, cnt + 1 });
		}
	}

	cout << answer << endl;
	vector<int> path;
	int n = 1;
	while (n != -1)
	{
		path.push_back(n);
		n = dp[n];
	}

	for (auto it = path.rbegin(); it != path.rend(); ++it) {
		cout << *it << " ";
	}
}