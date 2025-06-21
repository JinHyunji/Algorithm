#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[7];
int picked[7];

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
		picked[k] = arr[i];
		func(k + 1);
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