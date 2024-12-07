using System;

public class Solution {
    public int solution(int n, int[,] computers) {
        bool[] visited = new bool[n];
        int answer = 0;
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                DFS(i, n, computers, visited);
                ++answer;
            }
        }
        
        return answer;
    }
    
    static void DFS(int idx, int n, int[,] computers, bool[] visited) {
        if (visited[idx]) return;
        
        visited[idx] = true;
        
        for (int i = 0; i < n; i++) {
            if (computers[idx, i] == 1) {
                DFS(i, n, computers, visited);
            }
        }
    }
}