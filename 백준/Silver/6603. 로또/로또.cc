#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	while (true)
	{
		int K;
		cin >> K;
		if (K != 0)
		{
			int arr[13];
			for (int i = 0; i < K; i++)
			{
				cin >> arr[i];
			}

			vector<int> a(6, 0);
			vector<int> b(K - 6, 1);
			a.insert(a.end(), b.begin(), b.end());

			do
			{
				for (int i = 0; i < K; i++)
				{
					if (a[i] == 0)
					{
						cout << arr[i] << ' ';
					}
				}
				cout << '\n';
			} while (next_permutation(a.begin(), a.end()));

			cout << '\n';
		}
		else break;
	}
}