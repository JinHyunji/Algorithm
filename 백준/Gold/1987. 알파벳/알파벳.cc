#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int R, C;
vector<vector<char>> board;
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

// DFS 함수에서 반환값을 활용하여 최적의 거리 찾기
int DFS(int x, int y, int visited) {
    int maxDist = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;

        int nextChar = board[ny][nx] - 'A';
        if (visited & (1 << nextChar)) continue;  // 이미 방문한 문자면 패스

        // 비트마스크를 이용하여 방문 처리 후 DFS 재귀 호출
        maxDist = max(maxDist, 1 + DFS(nx, ny, visited | (1 << nextChar)));
    }

    return maxDist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> R >> C;
    board.resize(R, vector<char>(C));

    for (int r = 0; r < R; r++) {
        string input;
        cin >> input;
        for (int c = 0; c < C; c++) {
            board[r][c] = input[c];
        }
    }

    int startChar = board[0][0] - 'A';
    cout << DFS(0, 0, 1 << startChar);  // 초기 방문 상태: 1 << (첫 문자 위치)
    return 0;
}