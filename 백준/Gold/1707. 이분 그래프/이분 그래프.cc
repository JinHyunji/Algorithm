#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int K, V, E;

string BFS(const vector<vector<int>>& adjArr, vector<int>& color);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> K;

	string output;

	for (int k = 0; k < K; k++)
	{
		cin >> V >> E;
		vector<vector<int>> adjArr(V + 1);

		for (int e = 0; e < E; e++)
		{
			int n1, n2;
			cin >> n1 >> n2;
			adjArr[n1].push_back(n2);
			adjArr[n2].push_back(n1);
		}

		vector<int> color(V + 1, 0);

		output += BFS(adjArr, color) + "\n";
	}

	cout << output;
}

string BFS(const vector<vector<int>>& adjArr, vector<int>& color)
{
	queue<int> q;

	for (int start = 1; start < color.size(); start++)
	{
		if (color[start] == 0)
		{
			q.push(start);
			color[start] = 1;

			while (!q.empty())
			{
				int curr = q.front(); q.pop();

				for (int i = 0; i < adjArr[curr].size(); i++)
				{
					int next = adjArr[curr][i];
					if (color[next] == 0)
					{
						color[next] = color[curr] * -1;
						q.push(next);
					}
					else if (color[next] == color[curr]) return "NO";
				}
			}
		}

	}

	return "YES";
}