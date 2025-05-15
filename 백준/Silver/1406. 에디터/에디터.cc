#include <iostream>
#include <string>
#include <list>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string input;
	cin >> input;

	list<char> list;
	for (char ch : input)
	{
		list.push_back(ch);
	}

	auto cursor = list.end();

	int M;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		char comm;
		cin >> comm;

		if (comm == 'P')
		{
			char ch;
			cin >> ch;

			list.insert(cursor, ch);
		}
		else if (comm == 'L')
		{
			if (cursor == list.begin()) continue;
			cursor = std::prev(cursor);
		}
		else if (comm == 'D')
		{
			if (cursor == list.end()) continue;
			cursor = std::next(cursor);
		}
		else
		{
			if (cursor == list.begin()) continue;
			list.erase(std::prev(cursor));
		}
	}

	for (char ch : list)
		cout << ch;
}