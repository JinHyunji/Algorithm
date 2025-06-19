#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	vector<int> arr(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());

	vector<int> selected;
	for (int i = 0; i < N; i++)
		selected.emplace_back(i < M ? 0 : 1);

	do
	{
		for (int i = 0; i < N; i++)
			if (selected[i] == 0)
				cout << arr[i] << ' ';
		cout << '\n';
	} while (next_permutation(selected.begin(), selected.end()));
}