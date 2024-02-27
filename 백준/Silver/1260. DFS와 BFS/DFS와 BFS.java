import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static boolean[][] data;
	static boolean[] visited;
	static int N, M, V;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		// 정점개수, 간선개수, 탐색시작정점번호 순으로 입력
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		V = Integer.parseInt(st.nextToken());

		data = new boolean[N + 1][N + 1];
		visited = new boolean[N + 1];

		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			data[n][m] = true;
			data[m][n] = true;
		}

		// DFS
		visited[V] = true;
		DFS(V);

		// BFS
		System.out.println();
		visited = new boolean[N + 1];
		BFS();
	}

	// 깊이 우선 탐색
	public static void DFS(int node) {
		// base case
		System.out.print(node + " ");

		// recursive case
		for (int next = 1; next <= N; next++) {
			if (visited[next] == false && data[node][next] == true && data[next][node] == true) {
				visited[next] = true;
				DFS(next);
			}

		}

	}

	// 너비 우선 탐색
	public static void BFS() {
		Queue<Integer> q = new LinkedList<>();
		q.offer(V);
		visited[V] = true;

		while (!q.isEmpty()) {
			int node = q.poll();
			System.out.print(node + " ");
			
			for (int next = 1; next <= N; next++) {
				if (data[node][next] == true && data[next][node] == true && visited[next] == false) {
					q.offer(next);
					visited[next] = true;
				}
			}
		}
	}
}
