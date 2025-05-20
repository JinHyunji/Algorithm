#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	
	while (T--)
	{
		string methods;
		cin >> methods;

		int N;
		cin >> N;

		string str;
		cin >> str;
		
		str = str.substr(1, str.size() - 2);

		deque<int> dq;
		stringstream ss(str);
		string num;

		while (getline(ss, num, ','))
		{
			if (!num.empty())
				dq.push_back(stoi(num));
		}

		bool foundError = false;
		bool rev = false;
		for (int i = 0; i < (int)methods.size(); i++)
		{
			if (methods[i] == 'R')
			{
				rev = !rev;
			}
			else
			{
				if (dq.empty())
				{
					foundError = true;
					break;
				}
				if (rev)
					dq.pop_back();
				else
					dq.pop_front();
			}
		}

		if (foundError)
		{
			cout << "error\n";
			continue;
		}

		cout << "[";
		if (!dq.empty())
		{
			if (rev)
			{
				cout << dq.back(); dq.pop_back();
				while (!dq.empty())
				{
					cout << "," << dq.back();
					dq.pop_back();
				}
			}
			else
			{
				cout << dq.front(); dq.pop_front();
				while (!dq.empty())
				{
					cout << "," << dq.front();
					dq.pop_front();
				}
			}
		}
		cout << "]\n";
	}
}