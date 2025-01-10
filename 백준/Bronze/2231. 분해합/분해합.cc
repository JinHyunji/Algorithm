#include <iostream>

int main()
{
	int answer = 0;
	int N;
	std::cin >> N;

	for (int i = 1; i < N; i++)
	{
		int sum = 0;
		int pow = 1000000;
		int num = i;

		while (num % pow != 0)
		{
			sum += num / pow;
			num %= pow;
			pow /= 10;
		}

		sum += num / pow;

		if (i + sum == N)
		{
			answer = i;
			break;
		}
	}

	std::cout << answer;
}