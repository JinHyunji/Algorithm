import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static int K, V, E;
	static List<ArrayList<Integer>> adjList;
	static int[] colors;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		K = Integer.parseInt(br.readLine());
		
		for (int k = 0; k < K; k++) {
			st = new StringTokenizer(br.readLine());
			
			V = Integer.parseInt(st.nextToken());
			E = Integer.parseInt(st.nextToken());
			adjList = new ArrayList<>();
			colors = new int[V];
			
			for (int i = 0; i < V; i++) {
				adjList.add(new ArrayList<>());
			}
			
			for (int e = 0; e < E; e++) {
				st = new StringTokenizer(br.readLine());
				
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				
				adjList.get(a-1).add(b-1);
				adjList.get(b-1).add(a-1);
			}
			
			boolean isBipartite = true;
			for (int i = 0; i < V; i++) {
				if (colors[i] == 0) {
					if (!bfs(i)) {
						isBipartite = false;
						break;
					}
				}
			}
			
			if (isBipartite)
				System.out.println("YES");
			else
				System.out.println("NO");
		}
	}

	private static boolean bfs(int start) {
		Queue<Integer> q = new LinkedList<>();
		colors[start] = 1;
		q.offer(start);
		
		while (!q.isEmpty()) {
			int cur = q.poll();
			
			for (int next :adjList.get(cur)) {
				if (colors[next] == 0) {
					colors[next] = -colors[cur];
					q.offer(next);
				} else if (colors[next] == colors[cur]) {
					return false;
				}
			}
		}
		
		return true;
	}
}