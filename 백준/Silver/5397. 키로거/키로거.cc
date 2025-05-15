#include <iostream>
#include <string>
#include <list>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		string str;
		cin >> str;

		list<char> list;
		auto cursor = list.end();

		for (char ch : str)
		{
			if (ch == '-')
			{
				if (cursor == list.begin()) continue;
				list.erase(std::prev(cursor));
			}
			else if (ch == '<')
			{
				if (cursor == list.begin()) continue;
				cursor--;
			}
			else if (ch == '>')
			{
				if (cursor == list.end()) continue;
				cursor++;
			}
			else
			{
				list.insert(cursor, ch);
			}
		}

		for (char ch : list)
			cout << ch;

		cout << "\n";
	}
}