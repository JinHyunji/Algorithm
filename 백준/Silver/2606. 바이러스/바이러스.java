import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {

	static int N, R, count;
	static int[][] arr;
	static boolean[] visited;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		N = Integer.parseInt(br.readLine());
		R = Integer.parseInt(br.readLine());
		count = 0;
		arr = new int[N + 1][N + 1];
		visited = new boolean[N + 1];

		for (int i = 0; i < R; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());

			arr[a][b] = 1;
			arr[b][a] = 1;
		}

		DFS(1);
		
		System.out.println(count);
	}

	private static void DFS(int n) {
		visited[n] = true;
		
		for (int next = 2; next <= N; next++) {
			if (!visited[next] && arr[n][next] == 1) {
				DFS(next);
				count++;
			}
		}
	}

}