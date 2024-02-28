import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int[] sel;
	static int N, M;
	static boolean[] visited;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		sel = new int[M];

		visited = new boolean[N + 1];
		combination(0);
	}

	public static void combination(int sidx) {
		if (sidx == M) {
			for (int i = 0; i < sidx; i++) {
				System.out.print(sel[i] + " ");
			}
			System.out.println();
			return;
		}

		for (int i = 1; i <= N; i++) {
			if (visited[i] == true)
				continue;

			visited[i] = true;
			sel[sidx] = i;
			combination(sidx + 1);
			visited[i] = false;
		}
	}
}
