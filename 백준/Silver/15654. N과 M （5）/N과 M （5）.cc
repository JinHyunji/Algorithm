#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[8];
int picked[8];
bool isUsed[8];

void func(int k)
{
	if (k == M)
	{
		for (int i = 0; i < M; i++)
			cout << picked[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (isUsed[i]) continue;
		picked[k] = arr[i];
		isUsed[i] = true;
		func(k + 1);
		isUsed[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	func(0);
}