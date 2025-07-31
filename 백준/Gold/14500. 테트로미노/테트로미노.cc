#include <iostream>
#include <deque>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int N, M, maxVal = 0;
int paper[510][510];
vector<vector<pair<int,int>>> tetrominos = {
	{{0,0}, {0,1}, {0,2}, {0,3}},
	{{0,0}, {0,1}, {1,0}, {1,1}},
	{{0,0}, {1,0}, {2,0}, {2,1}},
	{{0,0}, {1,0}, {1,1}, {2,1}},
	{{0,0}, {0,1}, {0,2}, {1,1}},
	{{0,0}, {0,1}, {0,2}, {1,0}},
	{{0,0}, {0,1}, {1,1}, {2,1}},
	{{0,2}, {1,0}, {1,1}, {1,2}},
	{{0,1}, {1,1}, {2,0}, {2,1}},
	{{0,0}, {0,1}, {0,2}, {1,2}},
	{{0,0}, {0,1}, {1,0}, {2,0}},
	{{0,0}, {1,0}, {1,1}, {1,2}},
	{{0,1}, {0,2}, {1,0}, {1,1}},
	{{0,1}, {1,0}, {1,1}, {2,0}},
	{{0,0}, {0,1}, {1,1}, {1,2}},
	{{0,1}, {1,0}, {1,1}, {2,1}},
	{{0,1}, {1,0}, {1,1}, {1,2}},
	{{0,0}, {1,0}, {1,1}, {2,0}},
	{{0,0}, {1,0}, {2,0}, {3,0}}
};

// 남 동
int dx[] = { 1, 0 };
int dy[] = { 0, 1 };


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < M; y++)
		{
			cin >> paper[x][y];
		}
	}

	// 모든 곳에 놓아보며 수를 센다.
	for (vector<pair<int,int>> tetromino : tetrominos)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				int sum = 0;
				int canLied = true;
				for (auto [x, y] : tetromino)
				{
					int nx = i + x;
					int ny = j + y;

					if (nx < 0 || ny < 0 || nx >= N || ny >= M)
					{
						canLied = false;
						break;
					}

					sum += paper[nx][ny];
				}

				if (!canLied) continue;
				maxVal = max(sum, maxVal);
			}
		}
		
	}
	
	// 최대값을 출력한다.
	cout << maxVal;
}