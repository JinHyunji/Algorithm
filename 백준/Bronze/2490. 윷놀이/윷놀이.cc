#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int t = 0; t < 3; t++)
	{
		int f = 0, b = 0; // 배, 등
		for (int i = 0; i < 4; i++)
		{
			bool arr[4];
			cin >> arr[i];

			if (arr[i])
				b++;
			else
				f++;
		}

		switch (f)
		{
		case 0:
			cout << "E\n";
			break;
		case 1:
			cout << "A\n";
			break;
		case 2:
			cout << "B\n";
			break;
		case 3:
			cout << "C\n";
			break;
		case 4:
			cout << "D\n";
			break;
		}
	}
}