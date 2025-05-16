#include <iostream>
#include <stack>

using namespace std;

#define X first
#define Y second

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	stack<pair<int, int>> stack;
	stack.push({100000001, 0});

	for (int i = 1; i <= N; i++)
	{
		int height;
		cin >> height;

		while (stack.top().X < height)
			stack.pop();

		cout << stack.top().Y << " ";
		stack.push({ height, i });
	}
}