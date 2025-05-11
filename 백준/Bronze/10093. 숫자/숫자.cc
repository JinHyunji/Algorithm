#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b;
	cin >> a >> b;

	if (a > b)
	{
		cout << a - b - 1 << "\n";
		for (int i = b + 1; i < a; i++)
			cout << i << " ";
	}
	else if (a < b)
	{
		cout << b - a - 1 << "\n";
		for (int i = a + 1; i < b; i++)
			cout << i << " ";
	}
	else
	{
		cout << 0;
	}
}