#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

long long N, K = 0, actCnt = 0;

long long Copy();

int main()
{
	// 입력
	cin >> N;

	while (K < N)
	{
		if (K <= 0)
		{
			K++;
			actCnt++;
		}
		else
		{
			K += Copy();
			actCnt++;
		}
	}

	cout << actCnt;
}

long long Copy()
{
	if (K > N - K)
	{
		return N - K;
	}
	else
	{
		return K;
	}
}