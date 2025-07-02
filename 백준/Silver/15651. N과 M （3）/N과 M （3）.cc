#include <iostream>
using namespace std;

int N, M;
int picked[10];

void func(int k) 
{
	if (k == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << picked[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		picked[k] = i;
		func(k + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	func(0);

}