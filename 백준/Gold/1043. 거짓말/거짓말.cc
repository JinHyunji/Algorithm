#include <iostream>
#include <vector>
using namespace std;

int parent[51];

int Find(int x)
{
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Merge(int a, int b)
{
	int x = Find(a);
	int y = Find(b);

	if (x != y) parent[y] = x;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, M, T, answer = 0;
	cin >> N >> M >> T;

	for (int i = 1; i <= N; i++) parent[i] = i;

	for (int i = 0; i < T; i++)
	{
		int truePerson;
		cin >> truePerson;
		Merge(0, truePerson);
	}

	vector<vector<int>> parties(M);
	for (int i = 0; i < M;i++)
	{
		int count, first;
		cin >> count;

		if (count > 0)
		{
			cin >> first;
			parties[i].push_back(first);

			for (int j = 1; j < count; j++)
			{
				int person;
				cin >> person;
				parties[i].push_back(person);
				Merge(first, person);
			}
		}
	}

	for (const auto& party : parties)
	{
		bool flag = false;
		for (int i : party)
		{
			if (Find(i) == Find(0))
			{
				flag = true;
				break;
			}
		}

		if (!flag) answer++;
	}

	cout << answer;
	return 0;
}