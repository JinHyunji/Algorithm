import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int[] p;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int N, M;
		StringBuilder sb;

		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		p = new int[N + 1];
		sb = new StringBuilder();

		for (int j = 1; j <= N; j++) {
			p[j] = j;
		}

		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int act = Integer.parseInt(st.nextToken());
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());

			if (act == 0) {
				union(start, end);
			} else if (act == 1) {
				if (findset(start) != findset(end)) {
					sb.append("NO\n");
				} else {
					sb.append("YES\n");
				}
			}
		}

		System.out.println(sb);
	}

	static int findset(int start) {
		if (start != p[start]) {
			p[start] = findset(p[start]);
		}
		return p[start];
	}

	static void union(int start, int end) {
		p[findset(end)] = findset(start);
	}

}
