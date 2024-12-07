using System;
using System.Collections.Generic;

public class Solution {
    public int solution(string begin, string target, string[] words) {  
        bool isOk = false;
        
        for (int i = 0; i < words.Length; i++) {
            if (words[i].Equals(target)) {
                isOk = true;
                break;
            }
        }
        
        if (!isOk)
            return 0;
        
        return BFS(begin, target, words);
    }
    
    static int BFS(string begin, string target, string[] words) {
        Queue<Tuple<string, int>> queue = new Queue<Tuple<string, int>>();
        queue.Enqueue(Tuple.Create(begin, 0));
        
        while (queue.Count > 0) {
            var tuple = queue.Dequeue(); 
            string word = tuple.Item1;
            int count = tuple.Item2;
            
            if (word.Equals(target)) return count;
            
            for (int i = 0; i < words.Length; i++) {
                int cnt = 0;
                for (int j = 0; j < words[i].Length; j++) {
                    if (word[j].Equals(words[i][j])) {
                        cnt++;
                    }
                }
                if (cnt >= words[i].Length - 1) {
                    queue.Enqueue(Tuple.Create(words[i], count + 1));
                }
            }
        }
        
        return 0;
    }
}