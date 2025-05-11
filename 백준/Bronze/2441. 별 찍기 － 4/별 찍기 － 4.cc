#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < i; k++)
			cout << " ";

		for (int j = N - i; j > 0; j--)
			cout << "*";

		cout << "\n";
	}
}