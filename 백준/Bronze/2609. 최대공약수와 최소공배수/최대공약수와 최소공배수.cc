#include <iostream>

int GCD(int a, int b)
{
	if (b == 0) return a;
	return GCD(b, a % b);
}

int main()
{
	int a, b;

	std::cin >> a >> b;

	int gdc = GCD(a, b);

	std::cout << gdc << std::endl;
	std::cout << a * b / gdc;
}