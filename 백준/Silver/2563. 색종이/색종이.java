import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int[][] map = new int[101][101];
		int sum = 0;
		
		for (int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());

			for (int r = y; r < y + 10; r++) {
				for (int c = x; c < x + 10; c++) {
					map[r][c] = 1;
				}
			}
		}
		
		for (int[] i : map) {
			for (int j : i) {
				sum += j;
			}
		}

		System.out.println(sum);
	}

}