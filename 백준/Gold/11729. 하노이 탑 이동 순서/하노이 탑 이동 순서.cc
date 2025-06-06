#include <iostream>
#include <string>
using namespace std;
using ll = long long;

int N, answer = 0;
string output;

void func(int a, int b, int n)
{
	if (n == 0) return;

	func(a, 6 - a - b, n - 1);
	output += to_string(a) + ' ' + to_string(b) + '\n';
	answer++;
	func(6 - a - b, b, n - 1);
}

int main()
{
	cin >> N;

	func(1, 3, N);

	cout << answer << '\n';
	cout << output;
}