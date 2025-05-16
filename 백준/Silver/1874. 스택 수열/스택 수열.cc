#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	stack<int> stack;
	int num = 1, n;
	string output;
	for (int i = 0; i < N; i++)
	{
		cin >> n;

		while (num <= n)
		{
			stack.push(num++);
			output += "+\n";
		}

		if (stack.top() == n)
		{
			stack.pop();
			output += "-\n";
		}
		else if (stack.top() > n)
		{
			cout << "NO";
			return 0;
		}
	}

	cout << output;

}