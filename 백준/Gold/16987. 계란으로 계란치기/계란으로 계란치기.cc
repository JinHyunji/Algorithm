#include <iostream>
#include <algorithm>
using namespace std;

int N, maxCnt = 0, cnt = 0;
int S[8], W[8];

void func(int k)
{
	if (k == N)
	{
		maxCnt = max(cnt, maxCnt);
		return;
	}

	if (S[k] <= 0 || cnt == N - 1)
	{
		func(k + 1);
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (k == i || S[i] <= 0) continue;
		S[k] -= W[i];
		S[i] -= W[k];
		if (S[k] <= 0) cnt++;
		if (S[i] <= 0) cnt++;
		func(k + 1);
		if (S[k] <= 0) cnt--;
		if (S[i] <= 0) cnt--;
		S[i] += W[k];
		S[k] += W[i];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> S[i] >> W[i];

	func(0);
	cout << maxCnt;
}