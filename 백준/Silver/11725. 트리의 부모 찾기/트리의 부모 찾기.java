import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Main {

	static int N;
	static ArrayList<ArrayList<Integer>> arr;
	static int[] parent;
	static boolean[] visited;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();

		N = Integer.parseInt(br.readLine());
		arr = new ArrayList<>();
		parent = new int[N + 1];
		visited = new boolean[N + 1];
		for (int i = 0; i <= N; i++) {
			arr.add(new ArrayList<>());
		}
		
		for (int i = 0; i < N - 1; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());

			arr.get(a).add(b);
			arr.get(b).add(a);
		}

		BFS();
		
		for (int i = 2; i <= N; i++) {
			sb.append(parent[i]).append("\n");
		}
		
		System.out.println(sb);
	}

	private static void BFS() {
		Queue<Integer> q = new LinkedList<>();
		q.add(1);
		visited[1] = true;

		while (!q.isEmpty()) {
			int node = q.poll();

			for (int next : arr.get(node)) {
				if (!visited[next]) {
					parent[next] = node;
					visited[next] = true;
					q.add(next);
				}
			}
		}
	}
}