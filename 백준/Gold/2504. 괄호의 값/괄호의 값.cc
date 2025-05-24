#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string input;
	cin >> input;

	int num = 1;
	int sum = 0;
	stack<char> s;

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == '(')
		{
			num *= 2;
			s.push(input[i]);
		}
		else if (input[i] == '[')
		{
			num *= 3;
			s.push(input[i]);
		}
		else if (input[i] == ')')
		{
			if (s.empty() || s.top() != '(')
			{
				sum = 0;
				break;
			}

			if (input[i - 1] == '(')
			{
				sum += num;
			}

			s.pop();
			num /= 2;
		}
		else // input[i] == ']'
		{
			if (s.empty() || s.top() != '[')
			{
				sum = 0;
				break;
			}

			if (input[i - 1] == '[')
			{
				sum += num;
			}

			s.pop();
			num /= 3;
		}
	}

	if (s.empty()) cout << sum;
	else cout << 0;

	return 0;
}