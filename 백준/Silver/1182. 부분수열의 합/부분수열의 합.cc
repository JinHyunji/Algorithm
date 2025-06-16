#include <iostream>
using namespace std;

int N, S, cnt = 0;
int arr[20];

void func(int cur, int sum)
{
	if (cur == N)
	{
		if (sum == S)
			cnt++;
		return;
	}
	func(cur + 1, sum); // 수를 안 넣은 경우
	func(cur + 1, sum + arr[cur]); // 수를 넣은 경우
}

int main()
{
	cin >> N  >> S;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	func(0, 0);
	if (S == 0) cnt--; // 공집합이 포함되는 경우는 cnt를 하나 빼기
	cout << cnt;
}