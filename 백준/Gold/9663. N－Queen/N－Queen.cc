#include <iostream>
using namespace std;

int N, cnt = 0;
bool isUsed[40][3]; // 열, /방향 대각선, \방향 대각선

void func(int curr) // curr번째 row에 말을 배치하는 함수
{
	if (curr == N) // N개의 말을 놓았다면
	{
		cnt++;
		return;
	}

	for (int i = 0; i < N; i++) // (curr, i)에 퀸을 놓을 예정
	{
		if (!isUsed[i][0] && !isUsed[i + curr][1] && !isUsed[curr - i + N - 1][2])
		{
			isUsed[i][0] = true;
			isUsed[i + curr][1] = true;
			isUsed[curr - i + N - 1][2] = true;
			func(curr + 1);
			isUsed[i][0] = false;
			isUsed[i + curr][1] = false;
			isUsed[curr - i + N - 1][2] = false;
		}
	}
}

int main()
{
	cin >> N;
	func(0);
	cout << cnt;
}