#include <iostream>
using namespace std;
using ll = long long;

ll abs(ll a, ll b, ll c)
{
	if (b == 1) return a % c;

	ll Val = abs(a, b / 2, c);
	Val = Val * Val % c;

	if (b % 2 == 0) return Val;
	return Val * a % c;
}
int main()
{
	ll A, B, C;
	cin >> A >> B >> C;

	cout << abs(A, B, C);
}