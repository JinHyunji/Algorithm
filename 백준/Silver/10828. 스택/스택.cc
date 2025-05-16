#include <iostream>
#include <stack>
#include <string>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	stack<int> stack;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		if (str == "push")
		{
			int x;
			cin >> x;

			stack.push(x);
		}
		else if (str == "top")
		{
			if (stack.size() <= 0)
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << stack.top() << "\n";
			}
		}
		else if (str == "pop")
		{
			if (stack.size() <= 0)
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << stack.top() << "\n";
				stack.pop();
			}
		}
		else if (str == "size")
		{
			cout << stack.size() << "\n";
		}
		else
		{
			if (stack.empty())
			{
				cout << 1 << "\n";
			}
			else
			{
				cout << 0 << "\n";
			}
		}
	}
}