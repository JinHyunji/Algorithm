using System;
using System.Collections.Generic;

class Solution {
    static int[] dx = {0, 0, -1, 1};
    static int[] dy = {-1, 1, 0, 0};
    
    public int solution(int[,] maps) {
        bool[,] visited = new bool[maps.GetLength(0), maps.GetLength(1)];
        return BFS(maps, visited);
    }
    
    static int BFS(int[,] maps, bool[,] visited) {
        Queue<int[]> queue = new Queue<int[]>();
        queue.Enqueue(new int[] {0, 0, 1});
        visited[0,0] = true;
        
        while (queue.Count > 0) {
            int[] node = queue.Dequeue();
            
            if (node[0] == maps.GetLength(0)-1 && node[1] == maps.GetLength(1) -1) {
                return node[2];
            }
            
            for (int i = 0; i < 4; i++) {
                int nx = dx[i] + node[0];
                int ny = dy[i] + node[1];
                
                if (nx >= 0 && nx < maps.GetLength(0) && ny >= 0 && ny < maps.GetLength(1) && !visited[nx,ny] && maps[nx, ny] == 1) 
                {
                    queue.Enqueue(new int[] {nx, ny, node[2] + 1});
                    visited[nx,ny] = true;
                }
            }
        }
        
        return -1;
    }
}