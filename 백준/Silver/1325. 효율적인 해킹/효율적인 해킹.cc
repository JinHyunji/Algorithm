#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, cnt, maxValue;
vector<vector<int>> list;
vector<bool> visited;
vector<int> answer;

void DFS(int n);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	list.resize(N + 1);
	visited.resize(N + 1);

	for (int i = 0; i < M; i++)
	{
		int num1, num2;
		cin >> num1 >> num2;
		list[num2].push_back(num1);
	}

	for (int i = 1; i <= N; i++)
	{
		fill(visited.begin(), visited.end(), false);
		cnt = 0;
		DFS(i);

		if (cnt > maxValue)
		{
			maxValue = cnt;
			answer.clear();
			answer.push_back(i);
		}
		else if (cnt == maxValue)
		{
			answer.push_back(i);
		}
	}

	sort(answer.begin(), answer.end());
	for (int i : answer)
		cout << i << " ";
}

void DFS(int n)
{
	visited[n] = true;
	cnt++;

	for (int i : list[n])
	{
		if (!visited[i])
			DFS(i);
	}
}