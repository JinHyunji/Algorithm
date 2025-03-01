#include <iostream>
using namespace std;
using ll = long long;

ll Pow(ll a, ll b, ll c)
{
	if (b == 0) return 1;

	ll temp = Pow(a, b / 2, c);
	temp = temp * temp % c;
	if (b % 2 == 0) return temp;
	else return temp * a % c;
}

int main()
{
	int A, B, C;
	cin >> A >> B >> C;
	cout << Pow(A, B, C);
}