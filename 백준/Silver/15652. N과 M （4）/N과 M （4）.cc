#include <iostream>
using namespace std;

int N, M;
int arr[8];
bool isUsed[8];

void func(int k)
{
	if (k == M)
	{
		for (int i = 0; i < M; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	int st = 1;
	if (k != 0) st = arr[k - 1];
	for (int i = st; i <= N; i++)
	{
		arr[k] = i;
		func(k + 1);
	}
}

int main()
{
	cin >> N >> M;
	func(0);
}