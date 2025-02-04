#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, answer = 1;
vector<vector<int>> square;

int main()
{
	// 입출력 성능 향상
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 입력
	cin >> N >> M;
	square.resize(N, vector<int>(M));

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		for (int j = 0; j < M; j++)
		{
			square[i][j] = str[j] - '0';
		}
	}

	// 로직
	for (int max = N > M ? M : N; max > 1; max--) // 정사각형 한 변의 최대 길이
	{
		for (int i = 0; i < N - max + 1; i++) // 행의 개수
		{
			for (int j = 0; j < M - max + 1; j++) // 열의 개수
			{
				if (square[i][j] == square[i][j + max - 1] && square[i][j + max - 1] == square[i + max - 1][j] && square[i + max - 1][j] == square[i + max - 1][j + max - 1])
				{
					cout << max * max;
					return 0;
				}
				
			}
		}
	}

	// 출력
	cout << answer;
	return 0;
}