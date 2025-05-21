#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include <vector>
#include <sstream>
#include <stack>
using namespace std;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true)
	{
		string input;
		getline(cin, input);

		if (input == ".")
			break;

		stack<char> stack;
		string answer = "yes\n";
		bool isEnd = false;
		for (char ch : input)
		{
			if (ch == '(' || ch == '[')
			{
				stack.push(ch);
			}
			else if (ch == ')')
			{
				if (stack.empty() || stack.top() != '(')
				{
					cout << "no\n";
					isEnd = true;
					break;
				}

				stack.pop();
			}
			else if (ch == ']')
			{
				if (stack.empty() || stack.top() != '[')
				{
					cout << "no\n";
					isEnd = true;
					break;
				}
				stack.pop();
			}
		}

		if (isEnd) continue;

		if (stack.empty()) cout << "yes\n";
		else cout << "no\n";
	}
}