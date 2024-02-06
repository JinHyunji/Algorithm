import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());

		for (int t = 1; t <= T; t++) {

			StringTokenizer st = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());

			int[][] arr = new int[N][N];

			for (int r = 0; r < N; r++) {
				st = new StringTokenizer(br.readLine());

				for (int c = 0; c < N; c++) {
					arr[r][c] = Integer.parseInt(st.nextToken());
				}
			}

			int max = 0;

			for (int r = 0; r < N - M + 1; r++) {
				for (int c = 0; c < N - M + 1; c++) {
					int sum = 0;
					for (int r2 = r; r2 < r + 1 * M; r2++) {
						for (int c2 = c; c2 < c + 1 * M; c2++) {
							sum += arr[r2][c2];
						}
					}
					if (sum > max) {
						max = sum;
					}
				}
			}

			System.out.println("#" + t + " " + max);
		}
	}

}
