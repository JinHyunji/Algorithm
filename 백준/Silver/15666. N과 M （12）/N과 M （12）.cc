#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int arr[8];
bool isUsed[8];
int picked[8];

void func(int k, int preIdx)
{
	if (k == M)
	{
		for (int i = 0; i < M; i++)
			cout << picked[i] << ' ';
		cout << '\n';
		return;
	}

	int temp = 0; // 이전에 넣었던 수
	for (int i = preIdx; i < N; i++)
	{
		if (temp != arr[i])
		{
			temp = arr[i];
			picked[k] = arr[i];
			func(k + 1, i);
		}
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