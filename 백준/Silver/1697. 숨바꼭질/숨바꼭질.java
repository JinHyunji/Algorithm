import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static int N, K;
	static int[] check = new int[100001];

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());

		if (N == K) {
			System.out.println(0);
		} else {
			BFS();
		}

		
	}

	public static void BFS() {
		Queue<Integer> q = new LinkedList<>();
		q.add(N);
		check[N] = 1;

		while (!q.isEmpty()) {
			int node = q.poll();

			for (int i = 0; i < 3; i++) {
				int next;

				if (i == 0) {
					next = node - 1;
				} else if (i == 1) {
					next = node + 1;
				} else {
					next = node * 2;
				}
				
				if (next == K) {
					System.out.println(check[node]);
					return;
				}
				
				if (next >= 0 && next < check.length && check[next] == 0) {
					q.add(next);
					check[next] = check[node] + 1;
				}

			}
		}
	}

}
