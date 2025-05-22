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

	string input;
	cin >> input;

	stack<char> stack;
	bool prev = false;
	int answer = 0;

	for (char i : input)
	{
		if (i == '(')
		{
			prev = false;
			stack.push(i);
		}
		else
		{
			if (prev) // 괄호
			{
				stack.pop();
				answer++;
			}
			else // 레이저
			{
				prev = true;
				stack.pop();
				answer += stack.size();
			}
		}
	}

	cout << answer;
}