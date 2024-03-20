import java.util.*;

class Solution {
    
    static int[] dr = { -1, 1, 0, 0 }; // 상 하 좌 우
    static int[] dc = { 0, 0, -1, 1 };
    static int N, M;
    static int[] quan;
    
    public int solution(int[][] land) {
        N = land.length; // 세로 길이
        M = land[0].length; // 가로 길이
        quan = new int[M]; // 시추관 위치별 석유량

        boolean[][] visited = new boolean[N][M];
        
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                if (land[r][c] == 1 && visited[r][c] == false) {
                    bfs(land, visited, r, c);
                }
            }
        }
        
        int max = 0;
        
        for (int i = 0; i < quan.length; i++) {
            if (quan[i] > max) max = quan[i];
        }
        
        return max;
    }
    
    public void bfs(int[][] land, boolean[][] visited, int r, int c) {
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{r, c});
        visited[r][c] = true;
        
        int count = 1;
        Set<Integer> set = new HashSet<>();
        
        while (!q.isEmpty()) {
            int[] now = q.poll();
            set.add(now[1]);
            
            for (int i = 0; i < 4; i++) {
               int nr = now[0] + dr[i];
               int nc = now[1] + dc[i];
                        
               if (nr < 0 || nr >= N || nc < 0 || nc >= M) {
                   continue;
                }            
                
                if (land[nr][nc] == 1 && visited[nr][nc] == false) {
                    q.add(new int[]{nr, nc});
                    visited[nr][nc] = true;
                    count += 1;
                }
            }
        }
        
        for (int idx : set) {
            quan[idx] += count;
        }
        
        
    }
}