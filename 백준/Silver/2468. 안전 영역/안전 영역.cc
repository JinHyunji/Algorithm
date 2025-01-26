#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int map[101][101];
bool visited[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int x, int y, int height) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                if (!visited[nx][ny] && map[nx][ny] > height) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main() {
    cin >> N;
    int maxHeight = 0;

    // 입력 받기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            maxHeight = max(maxHeight, map[i][j]);
        }
    }

    int result = 0;

    // 높이별로 영역 개수 계산
    for (int height = 0; height <= maxHeight; height++) {
        fill(&visited[0][0], &visited[0][0] + 101 * 101, false);
        int safeAreas = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j] && map[i][j] > height) {
                    bfs(i, j, height);
                    safeAreas++;
                }
            }
        }

        result = max(result, safeAreas);
    }

    cout << result << endl;
    return 0;
}
