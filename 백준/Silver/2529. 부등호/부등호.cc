#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;

int K;
long long Max, Min;
vector<char> signs;
vector<bool> visited(10);
vector<int> picked;

void Pick();

int main()
{
	// 입출력 성능 향상
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 입력
	cin >> K;

	signs.resize(K);

	for (int i = 0; i < K; i++)
	{
		cin >> signs[i];
	}

	// 로직
	Max = 0;
	Min = LLONG_MAX;
	
	// 1) 10개 중에서 K+1개를 고른다.
	Pick();

	// 출력
	cout << Max << endl;

	string minStr = to_string(Min);
	if (minStr.size() < static_cast<size_t>(K + 1))
		cout << '0';
	cout << Min << endl;
}

void Pick()
{
	if (picked.size() == static_cast<size_t>(K + 1))
	{
		for (size_t i = 0; i < signs.size(); i++)
		{
			// 2) 부등호 사이에 들어갈 수 있는지 확인한다.
			if ((picked[i] > picked[i + 1] && signs[i] == '>') || 
				(picked[i] < picked[i + 1] && signs[i] == '<'))
				continue;
			return;
		}
		
		// 2-1) 최댓값과 최솟값을 갱신한다.
		string str = "";
		for (int i : picked)
			str += to_string(i);

		long long num = stoll(str);
		Max = max(Max, num);
		Min = min(Min, num);

		return;
	}

	for (int i = 0; i < 10; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			picked.push_back(i);
			Pick();
			picked.pop_back();
			visited[i] = false;
		}
	}

}