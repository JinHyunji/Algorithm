#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> a(M, 0);
	vector<int> b(N - M, 1);
	a.insert(a.end(), b.begin(), b.end());

	do
	{
		for (int i = 0; i < N; i++)
			if (a[i] == 0)
				cout << i + 1 << ' ';
		cout << '\n';
	} while (next_permutation(a.begin(), a.end()));
}