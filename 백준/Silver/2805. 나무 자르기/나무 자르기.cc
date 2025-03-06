#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <string>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	ll N, M, result = 0;
	cin >> N >> M;
	vector<ll> trees(N);

	for (ll i = 0; i < N; i++)
	{
		cin >> trees[i];
	}

	int minH = 0, maxH = *max_element(trees.begin(), trees.end()) - 1;
	while (minH <= maxH)
	{
		ll midH = (minH + maxH) / 2, sum = 0;

		for (ll tree : trees)
		{
			if (tree > midH)
				sum += tree - midH;
		}

		if (sum >= M)
		{
			result = midH;
			minH = midH + 1;
		}
		else
		{
			maxH = midH - 1;
		}
	}

	cout << result;
	return 0;
}