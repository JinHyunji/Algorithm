#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	queue<int> q;
	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;

		if (input == "push")
		{
			int x;
			cin >> x;

			q.push(x);
		}
		else if (input == "front")
		{
			if (q.empty()) cout << -1 << "\n";
			else cout << q.front() << "\n";
		}
		else if (input == "back")
		{
			if (q.empty()) cout << -1 << "\n";
			else cout << q.back() << "\n";
		}
		else if (input == "size")
		{
			cout << q.size() << "\n";
		}
		else if (input == "pop")
		{
			if (q.empty()) cout << -1 << "\n";
			else
			{
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else
		{
			if (q.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
	}
}