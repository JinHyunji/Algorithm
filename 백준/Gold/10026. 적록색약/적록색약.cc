#include <iostream>
#include <queue>
using namespace std;

const static int MAX = 100;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int N;
char map[MAX][MAX];
bool visited[MAX][MAX][2];
int answer[2];

void BFS(int x, int y, char color, bool id)
{
    queue<pair<int,int>> q;
    q.push({x, y});
    visited[x][y][id] = true;

    while (!q.empty())
    {
        auto [x, y] = q.front(); q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

            if (id && (color == 'R' || color == 'G') && (map[nx][ny] == 'R' || map[nx][ny] == 'G') && !visited[nx][ny][id])
            {
                q.push({nx, ny});
                visited[nx][ny][id] = true;
            }
            
            if (map[nx][ny] == color && !visited[nx][ny][id])
            {
                q.push({nx, ny});
                visited[nx][ny][id] = true;
            }
        }
    }
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int x = 0; x < N; x++) 
    {
        for (int y = 0; y < N; y++) 
        {
            cin >> map[x][y];
        }
    }

    for (int x = 0; x < N; x++) 
    {
        for (int y = 0; y < N; y++) 
        {
            if (!visited[x][y][0]) // 색약이 아닌 경우
            {
                answer[0]++;
                BFS(x, y, map[x][y], false);
            }
            
            if (!visited[x][y][1]) // 색약인 경우
            {
                answer[1]++;
                BFS(x, y, map[x][y], true);
            }
        }
    }

    cout << answer[0] << " " << answer[1];
    return 0;
}