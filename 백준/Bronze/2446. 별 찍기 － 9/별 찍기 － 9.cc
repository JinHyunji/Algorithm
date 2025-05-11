#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 1; i <= 2 * N - 1; i++)
	{
		for (int j = 1; j < N - abs(N - i); j++)
			cout << " ";

		for (int j = 0; j < 2 * abs(i - N) + 1; j++)
			cout << "*";

		cout << "\n";
	}
}