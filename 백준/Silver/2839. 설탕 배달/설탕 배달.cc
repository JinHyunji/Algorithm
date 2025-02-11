#include <iostream>
#include <algorithm>
using namespace std;

int N, remain = 0, answer = -1;



int main()
{
	cin >> N;

	for (int i = N / 5; i >= 0; i--)
	{
		remain = N - (5 * i);

		if (remain % 3 == 0)
		{
			answer = (i + remain / 3);
			break;
		}
	}

	cout << answer;
}