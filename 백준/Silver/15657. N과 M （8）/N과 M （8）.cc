#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int arr[8];
int picked[8];

void func(int k, int pre)
{
	if (k == M)
	{
		for (int i = 0; i < M; i++)
			cout << picked[i] << ' ';
		cout << '\n';
		return;
	}

	int st = 0;
	if (k != 0) st = pre;
	for (int i = st; i < N; i++)
	{
		picked[k] = arr[i];
		func(k + 1, i);
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
	func(0, 0);
}