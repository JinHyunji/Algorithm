#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string wheels[4];

void func(int n, int dir)
{
	int dirs[4] = {};
	dirs[n] = dir;

	int idx = n;
	while (idx > 0 && wheels[idx][6] != wheels[idx - 1][2])
	{
		dirs[idx - 1] = -dirs[idx];
		idx--;
	}

	idx = n;
	while (idx < 3 && wheels[idx][2] != wheels[idx + 1][6])
	{
		dirs[idx + 1] = -dirs[idx];
		idx++;
	}

	for (int i = 0; i < 4; i++)
	{
		if (dirs[i] == 1) rotate(wheels[i].begin(), wheels[i].begin() + 7, wheels[i].end());
		else if (dirs[i] == -1) rotate(wheels[i].begin(), wheels[i].begin() + 1, wheels[i].end()); 
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 4; i++)
		cin >> wheels[i];

	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int num, dir;
		cin >> num >> dir;

		func(num - 1, dir);
	}

	int sum = 0;
	for (int i = 0; i < 4; i++)
		if (wheels[i][0] == '1') sum += (1 << i);

	cout << sum;
}