#include <iostream>
#include <vector>
#include <string>
using namespace std;

string output;
int T, N, answer;
vector<int> students;
vector<bool> visited;
vector<bool> finished;

void DFS(int node)
{
	visited[node] = true;
	int next = students[node];

	if (!visited[next])
	{
		DFS(next);
	}
	else if (!finished[next])
	{
		for (int i = next; i != node; i = students[i])
			answer++;
		answer++;
	}

	finished[node] = true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> N;

		students.assign(N + 1, 0);
		visited.assign(N + 1, false);
		finished.assign(N + 1, false);

		for (int i = 1; i <= N; i++)
		{
			cin >> students[i];
		}

		answer = 0;

		for (int i = 1; i <= N; i++)
		{
			if (!visited[i])
				DFS(i);
		}

		output += to_string(N - answer) + "\n";
	}

	cout << output;
}