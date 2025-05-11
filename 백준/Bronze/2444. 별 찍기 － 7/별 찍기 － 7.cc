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
		for (int k = 0; k < abs(i - N); k++)
			cout << " ";

		for (int j = 0; j < (N - abs(i - N)) * 2 - 1; j++)
			cout << "*";

		cout << "\n";
	}
}