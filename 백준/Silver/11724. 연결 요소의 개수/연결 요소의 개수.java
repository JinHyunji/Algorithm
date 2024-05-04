import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {

	static int N, M, count;
	static int[][] arr;
	static boolean[] visited;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		count = 0;
		arr = new int[N + 1][N + 1];
		visited = new boolean[N + 1];

		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());

			arr[a][b] = 1;
			arr[b][a] = 1;
		}

		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				DFS(i);
				count++;
			}
		}

		System.out.println(count);
	}

	private static void DFS(int n) {
		visited[n] = true;
		
		for (int next = 1; next <= N; next++) {
			if (!visited[next] && arr[n][next] == 1) {
				DFS(next);
			}
		}
	}

}