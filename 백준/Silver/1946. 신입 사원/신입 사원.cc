#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int T, N;
string output = "";

int main()
{
	// 입출력 성능 향상
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 입력
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> N;
		vector<pair<int, int>> rank(N);

		for (int n = 0; n < N; n++)
		{
			int a, b; // 서류, 면접 순위
			cin >> a >> b;
			rank[n] = make_pair(a, b);
		}

		// 오름차순 정렬
		sort(rank.begin(), rank.end(), [](pair<int, int> a, pair<int, int> b)
			{
				return a.first < b.first;
			});

		int count = 1; // 선발 인원(첫 번째 지원자는 무조건 뽑음)
		int minRank = rank[0].second; // 면접 순위 최솟값

		for (int i = 1; i < N; i++) // 두 번째 지원자부터 탐색
		{
			if (rank[i].second < minRank) // 면접 순위의 최솟값보다 더 낮을 경우
			{
				count++; // 선발 인원에 포함
				minRank = rank[i].second; // 최솟값 갱신
			}
		}

		output += to_string(count) + "\n";
	}

	// 출력
	cout << output << endl;
}