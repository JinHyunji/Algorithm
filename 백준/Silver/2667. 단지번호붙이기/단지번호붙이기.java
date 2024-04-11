import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

	static int N, sum, idxs;
	static int[][] map;
	static int[] count;
	static boolean[][] visited;
	static int[] dr = { -1, 1, 0, 0 };
	static int[] dc = { 0, 0, -1, 1 };
	static StringBuilder sb = new StringBuilder();

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		N = Integer.parseInt(br.readLine());
		sum = 0;
		idxs = 0;
		map = new int[N][N];
		count = new int[N * N];
		visited = new boolean[N][N];

		for (int r = 0; r < N; r++) {
			String input = br.readLine();
			for (int c = 0; c < N; c++) {
				map[r][c] = input.charAt(c) - '0';
			}
		}

		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (!visited[r][c] && map[r][c] == 1) {
					check(r, c, idxs);
					++sum;
					++idxs;
				}
			}
		}

		int[] tmp = Arrays.copyOfRange(count, 0, sum);
		Arrays.sort(tmp);
		sb.append(sum);
		
		for (int i = 0; i < tmp.length; i++) {
			sb.append("\n").append(tmp[i]);
		}

		System.out.println(sb);
	}

	private static void check(int r, int c, int idx) {
		visited[r][c] = true;
		count[idx]++;

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr >= 0 && nc >= 0 && nr < N && nc < N && !visited[nr][nc] && map[nr][nc] == 1) {
				check(nr, nc, idx);
			}
		}
	}

}
