import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {

	static int[][] adj;
	static int[] degree;
	static boolean[] visited;
	static int V, E;
	static StringBuilder sb;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		for (int t = 1; t <= 10; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());

			V = Integer.parseInt(st.nextToken());
			E = Integer.parseInt(st.nextToken());

			adj = new int[V + 1][V + 1];
			degree = new int[V + 1];
			visited = new boolean[V + 1];
			sb = new StringBuilder();

			st = new StringTokenizer(br.readLine());

			for (int i = 0; i < E; i++) {
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				adj[a][b] = 1;
				degree[b]++;
			}

			Queue<Integer> queue = new LinkedList<>();

			for (int i = 1; i <= V; i++) {
				if (degree[i] == 0) {
					queue.offer(i);
					visited[i] = true;
				}
			}

			while (!queue.isEmpty()) {
				int curr = queue.poll();
				sb.append(curr + " ");

				for (int i = 1; i <= V; i++) {
					if (adj[curr][i] == 1) {
						degree[i]--;
						if (degree[i] == 0) {
							queue.offer(i);
						}
					}
				}
			}

			System.out.println("#" + t + " " + sb);
		}
	}
}
