#include <iostream>
#include <map>
using namespace std;

int main()
{
	int N, X;
	cin >> N;

	map<string, int> map;
	
	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input >> X;

		if (map.count(input) == 1)
		{
			map[input] += X;
		}
		else
		{
			map[input] = X;
		}
	}

	for (const auto& value : map)
	{
		if (value.second == 5)
		{
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";

	return 0;
}