#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int K;
	cin >> K;

	stack<int> stack;
	for (int k = 0; k < K; k++)
	{
		int x;
		cin >> x;

		if (x == 0)
		{
			stack.pop();
		}
		else
		{
			stack.push(x);
		}
	}

	int sum = 0;
	while (!stack.empty())
	{
		sum += stack.top(); stack.pop();
	}

	cout << sum;
}