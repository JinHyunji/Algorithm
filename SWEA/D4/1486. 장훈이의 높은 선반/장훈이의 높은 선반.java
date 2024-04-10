import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {

	static int N, B, min;
	static int[] heights;
	static StringBuilder sb = new StringBuilder();

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		int T = Integer.parseInt(br.readLine());

		start : for (int t = 1; t <= T; t++) {
			sb.append("#" + t + " ");

			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			B = Integer.parseInt(st.nextToken());
			min = 200000;
			heights = new int[N];
			st = new StringTokenizer(br.readLine());

			for (int i = 0; i < N; i++) {
				heights[i] = Integer.parseInt(st.nextToken());
				if (heights[i] == B) {
					sb.append(0).append("\n");
					continue start;
				}
			}
			
			for (int ea = 1; ea <= N; ea++) {
				combi(ea, 0, 0, 0);
			}
			
			sb.append(Math.abs(min - B)).append("\n");
		}
		System.out.println(sb);
	}

	private static void combi(int ea, int idx, int sidx, int sum) {
		if (sidx == ea) {
			if (sum >= B) {
				min = Math.min(sum, min);
			}
			return;
		}
		if (idx == N) return;
		
		combi(ea, idx+1, sidx+1, sum+heights[idx]);
		combi(ea, idx+1, sidx, sum);
	}
}
