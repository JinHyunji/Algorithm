import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N, M;
	static int[] result;
	static StringBuilder tmp = new StringBuilder();;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		result = new int[M];
		
		perm(0);
		System.out.println(tmp);
		
	}

	private static void perm(int idx) {
		if (idx == M) {
			for (int i = 0; i < M; i++) {
				tmp.append(result[i] + " ");
			}
			tmp.append("\n");
			return;
		}
		for (int i = 1; i <= N; i++) {
			result[idx] = i;
			perm(idx + 1);
		}
	}
}
