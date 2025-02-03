#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const vector<vector<char>> chess_white = {
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B' ,'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B' ,'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
};

const vector<vector<char>> chess_black = {
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B' ,'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B' ,'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
};

int N, M, answer;
vector<vector<char>> input;

int main()
{
	// 입출력 성능 향상
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 입력
	cin >> N >> M;

	input.resize(N, vector<char>(M));

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		for (int j = 0; j < M; j++)
		{
			input[i][j] = str[j];
		}
	}

	// 로직
	answer = 2500;
	for (int k = 0; k < N - 7; k++)
	{
		for (int l = 0; l < M - 7; l++)
		{
			int cnt_white = 0;
			int cnt_black = 0;

			for (int i = k; i < k + 8; i++)
			{
				for (int j = l; j < l + 8; j++)
				{
					if (chess_white[i - k][j - l] != input[i][j])
						cnt_white++;

					if (chess_black[i - k][j - l] != input[i][j])
						cnt_black++;
				}
			}

			cnt_white = min(cnt_white, cnt_black);
			answer = min(answer, cnt_white);
		}
	}

	// 출력
	if (answer == 2500) answer = 0;
	cout << answer;
}