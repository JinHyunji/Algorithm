import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static int N, M;
	static int[] arr, result;
	static boolean[] visited;
	static StringBuilder sb = new StringBuilder();

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		arr = new int[N];
		result = new int[M];
		visited = new boolean[N];

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		Arrays.sort(arr);

		perm(0, 0);

		System.out.println(sb);
	}

	private static void perm(int idx, int sidx) {
		if (sidx == M) {
			for (int i = 0; i < M; i++) {
				sb.append(result[i] + " ");
			}
			sb.append("\n");
			return;
		}
		if (idx == N)
			return;

		int before = 0;

		for (int i = idx; i < N; i++) {
			if (!visited[i] && before != arr[i]) {
				result[sidx] = arr[i];
				visited[i] = true;
				before = arr[i];
				perm(i + 1, sidx + 1);
				visited[i] = false;
			}
		}
	}
}