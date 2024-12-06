using System;
using System.Collections.Generic;

public class Solution {
    
    public int solution(int x, int y, int n) {
        HashSet<int> visited = new HashSet<int>();
        if (x == y) return 0;
        return BFS(x, 0, y, n, visited);
    }
    
    public static int BFS(int num, int cnt, int y, int n, HashSet<int> visited) {
            Queue<int[]> queue = new Queue<int[]>();
            queue.Enqueue(new int[]{num, cnt});
            visited.Add(num);
        
            while (queue.Count > 0) {
                int[] node = queue.Dequeue();
                
                if (node[0] == y) return node[1];

                if (!visited.Contains(node[0]*3) && node[0]*3 <= y) {
                    queue.Enqueue(new int[]{node[0]*3, node[1]+1});
                    visited.Add(node[0]*3);
                }
                    
                if (!visited.Contains(node[0]*2) && node[0]*2 <= y) {
                    queue.Enqueue(new int[]{node[0]*2, node[1]+1});
                    visited.Add(node[0]*2);
                }
                
                if (!visited.Contains(node[0] + n) && node[0] + n <= y) {
                    queue.Enqueue(new int[]{node[0]+n, node[1]+1});
                    visited.Add(node[0]+n);
                }
            }
            
            return -1;
        }
}