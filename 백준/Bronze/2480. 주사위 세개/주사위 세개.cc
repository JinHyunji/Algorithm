#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, c;
	cin >> a >> b >> c;

	if (a != b && a != c && b != c) // 모두 다른 눈
	{
		int maxV = a;
		maxV = max(a, max(b, c));
		cout << maxV * 100;
	}
	else if ((a == b && a != c) || (a == c && a != b) || (b == c && b != a)) // 같은 눈 2개
	{
		if (a == b)
		{
			cout << 1000 + a * 100;
		}
		else if (b == c)
		{
			cout << 1000 + b * 100;
		}
		else
		{
			cout << 1000 + c * 100;
		}
	}
	else // 같은 눈 3개
	{
		cout << 10000 + a * 1000;
	}
}