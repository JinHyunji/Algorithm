#include <iostream>
#include <unordered_map>
using namespace std;
using ll = long long;

ll N, P, Q;
unordered_map<ll, ll> dp;

ll Solve(ll n)
{
	if (n == 0) return 1;
	if (dp.count(n)) return dp[n];
	return dp[n] = Solve(n / P) + Solve(n / Q);
}

int main()
{
	// 입력
	cin >> N >> P >> Q;

	// 출력
	cout << Solve(N) << endl;
}