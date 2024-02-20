import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static int N, M, V;
	static int[][] adjMatrix;
	static int[] visited;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		V = Integer.parseInt(st.nextToken());

		adjMatrix = new int[N + 1][N + 1];
		visited = new int[N + 1];

		for (int m = 0; m < M; m++) {
			st = new StringTokenizer(br.readLine());

			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());

			adjMatrix[a][b] = 1;
			adjMatrix[b][a] = 1;
		}

		visited[V] = 1;
		DFS(V);

		visited = new int[N + 1];
		System.out.println();
		BFS();
	}

	public static void DFS(int node) {
		System.out.print(node + " ");

		for (int next = 1; next <= N; next++) {
			if (visited[next] == 1 || adjMatrix[node][next] == 0)
				continue;

			visited[next] = 1;
			DFS(next);
		}
	}

	public static void BFS() {
		Queue<Integer> q = new LinkedList<>();
		
		visited[V] = 1;
		q.offer(V);

		while (!q.isEmpty()) {
			int node = q.poll();
			System.out.print(node + " ");
			
			for (int next = 1; next <= N; next++) {
				if (visited[next] == 1 || adjMatrix[node][next] == 0)
					continue;
				visited[next] = 1;
				q.offer(next);
			}
		}
	}

}
