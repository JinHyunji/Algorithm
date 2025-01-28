#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, A, B, M;
vector<int> graph[101];
bool visited[101];

int bfs(int start, int target) {
    queue<pair<int, int>> q; // (현재 노드, 촌수)
    q.push({start, 0});
    visited[start] = true;

    while (!q.empty()) {
        int cur = q.front().first;
        int depth = q.front().second;
        q.pop();

        if (cur == target) return depth; // 목표 노드 찾으면 촌수 반환

        for (int next : graph[cur]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push({next, depth + 1});
            }
        }
    }

    return -1; // 촌수를 계산할 수 없는 경우
}

int main() {
    cin >> N >> A >> B >> M;

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x); // 양방향 연결
    }

    cout << bfs(A, B);
    return 0;
}
