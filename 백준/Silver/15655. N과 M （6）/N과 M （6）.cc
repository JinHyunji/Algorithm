#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> arr;
vector<int> picked;
vector<vector<int>> answer;

void func(int idx, int sIdx)
{
	if (sIdx == M)
	{
		answer.emplace_back(picked);
		return;
	}

	if (idx == N) return;

	picked[sIdx] = arr[idx];
	func(idx + 1, sIdx + 1);
	func(idx + 1, sIdx);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	arr.resize(N);
	picked.resize(M, 0);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	func(0, 0);
	for (const auto& ans : answer)
	{
		for (int i = 0; i < M; i++)
			cout << ans[i] << ' ';
		cout << '\n';
	}
}