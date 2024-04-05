import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static int N, M, max;
	static int[][] map;
	static int[] dr = { -1, 1, 0, 0 };
	static int[] dc = { 0, 0, -1, 1 };

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		max = 0;
		map = new int[N][M];

		for (int r = 0; r < N; r++) {
			st = new StringTokenizer(br.readLine());
			for (int c = 0; c < M; c++) {
				map[r][c] = Integer.parseInt(st.nextToken());
			}
		}

		wall(0, 0, 0);

		System.out.println(max);

	}

	public static void wall(int r, int c, int count) {
		if (count == 3) {
			safeZone();
			return;
		}

		while (r < N && c < M) {
			if (map[r][c] == 0) {
				map[r][c] = 1;
				wall(r, c, count + 1);
				map[r][c] = 0;
			}

			c++;
			if (c == M) {
				r++;
				c = 0;
			}
		}
	}

	private static int safeZone() {
		int ans = 0;
		int[][] mapCopy = new int[N][M];

		for (int i = 0; i < map.length; i++) {
			mapCopy[i] = map[i].clone();
		}

		virus(mapCopy);

		for (int r = 0; r < N; r++) {
			for (int c = 0; c < M; c++) {
				if (mapCopy[r][c] == 0) {
					ans++;
				}
			}
		}

		if (ans > max) {
			max = ans;
		}
		return max;
	}

	private static void virus(int[][] mapCopy) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {

				if (mapCopy[i][j] == 2) {

					for (int k = 0; k < 4; k++) {
						int nr = i + dr[k];
						int nc = j + dc[k];

						if (nr < N && nc < M && nr >= 0 && nc >= 0 && mapCopy[nr][nc] == 0) {
							mapCopy[nr][nc] = 2;
							virus(mapCopy);
						}
					}
				}
			}
		}
	}
}