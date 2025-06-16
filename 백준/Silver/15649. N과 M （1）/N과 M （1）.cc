#include <iostream>
using namespace std;

int N, M;
int arr[10];
bool isUsed[10];

void func(int k)
{
	if (k == M)
	{
		for (int i = 0; i < M; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (!isUsed[i])
		{
			arr[k] = i;
			isUsed[i] = true;
			func(k + 1);
			isUsed[i] = false;
		}
	}
}

int main()
{
	cin >> N >> M;
	func(0);
}