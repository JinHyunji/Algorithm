import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {

	static int[][] adjArr;
	static int[] max;
	static int N, start, ans, level;
	static boolean[] visited;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		for (int t = 1; t < 11; t++) {
			st = new StringTokenizer(br.readLine());
			
			N = Integer.parseInt(st.nextToken());
			start = Integer.parseInt(st.nextToken());
			
			adjArr = new int[101][101];
			visited = new boolean[101];
			max = new int[100];
			
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < N/2; i++) {
				int A = Integer.parseInt(st.nextToken());
				int B = Integer.parseInt(st.nextToken());
				adjArr[A][B] = 1;
			}
			
			ans = 0;
			BFS(start);
			
			System.out.println("#" + t + " " + ans);
		}
	}
	
	public static void BFS(int start) {
		Queue<int[]> q = new LinkedList<>();
		q.add(new int[] {start, 0});
		visited[start] = true;
		
		while (!q.isEmpty()) {
			int[] node = q.poll();
			
			if (max[node[1]] < node[0])
				max[node[1]] = node[0];
			
			for (int next = 1; next <= 100; next++) {
				if (visited[next] == false && adjArr[node[0]][next] == 1) {
					q.add(new int[] {next, node[1]+1});
					visited[next] = true;
				}
			}
			
		}
		
		for (int i = 99; i >= 0; i--) {
			if (max[i] != 0) {
				ans = max[i];
				return;
			}
		}
	}
}
