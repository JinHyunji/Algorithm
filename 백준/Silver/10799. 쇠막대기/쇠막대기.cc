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

	stack<pair<int, char>> stack;
	vector<int> laser(100001);
	int curr = 0;
	bool prev = false;
	int answer = 0;

	for (char i : input)
	{
		if (i == '(')
		{
			prev = false;
			stack.push({ ++curr, i });
		}
		else
		{
			if (prev)
			{
				auto [num, p] = stack.top(); stack.pop();
				answer += (laser[num] + 1);
				laser[num] = -1;
			}
			else
			{
				prev = true;
				curr--;
				stack.pop();
				for (int idx = 1; idx <= curr; idx++)
				{
					if (idx == -1 || idx == 0) continue;
					laser[idx]++;
				}
			}
		}
	}

	cout << answer;
}