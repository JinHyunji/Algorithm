import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static char[][] map;
	static boolean[][] visited;
	static int N, count1, count2;
	static int[] dr = { -1, 1, 0, 0 };
	static int[] dc = { 0, 0, -1, 1 };

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		N = Integer.parseInt(br.readLine());
		map = new char[N][N];
		visited = new boolean[N][N];

		for (int r = 0; r < N; r++) {
			String input = br.readLine();
			for (int c = 0; c < N; c++) {
				map[r][c] = input.charAt(c);
			}
		}

		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (!visited[r][c]) {
					if (map[r][c] == 'R') {
						DFS(r, c, 'R');
						count1++;
					} else if (map[r][c] == 'G') {
						DFS(r, c, 'G');
						count1++;
					} else {
						DFS(r, c, 'B');
						count1++;
					}
				}
			}
		}

		visited = new boolean[N][N];

		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (!visited[r][c]) {
					if (map[r][c] == 'R' || map[r][c] == 'G') {
						DFS2(r, c, 'R', 'G');
						count2++;
					} else {
						DFS(r, c, 'B');
						count2++;
					}
				}
			}
		}

		System.out.println(count1 + " " + count2);
	}

	private static void DFS2(int r, int c, char col1, char col2) {
		visited[r][c] = true;

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr >= 0 && nr < N && nc >= 0 && nc < N && !visited[nr][nc] && (map[nr][nc] == col1 || map[nr][nc] == col2)) {
				DFS2(nr, nc, col1, col2);
			}
		}
	}

	private static void DFS(int r, int c, char col) {
		visited[r][c] = true;

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr >= 0 && nr < N && nc >= 0 && nc < N && !visited[nr][nc] && map[nr][nc] == col) {
				DFS(nr, nc, col);
			}
		}
	}

}
