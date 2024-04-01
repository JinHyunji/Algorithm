import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N, count;
	static int[][] map;
	static boolean[][] visited;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		N = Integer.parseInt(br.readLine());
		map = new int[N][N];
		visited = new boolean[N][N];

		for (int r = 0; r < N; r++) {
			st = new StringTokenizer(br.readLine());
			for (int c = 0; c < N; c++) {
				map[r][c] = Integer.parseInt(st.nextToken());
			}
		}

		DFS(0, 1, 1); // 인덱스 + 1 해야 됨

		System.out.println(count);
	}

	private static void DFS(int r, int c, int dir) {
		if (r == N - 1 && c == N - 1) {
			count++;
			return;
		}

		// 현재 가로라면 (1)
		if (dir == 1) {
			// 가로로 가 (r, c+1)
			if (r >= 0 && c+1 >= 0 && r < N && c+1 < N && map[r][c+1] == 0) {
				DFS(r, c+1, 1);
			}
			// 대각선으로 가 (r+1, c+1)
			if (r+1 >= 0 && c+1 >= 0 && r+1 < N && c+1 < N && map[r+1][c+1] == 0 && map[r][c+1] == 0 && map[r+1][c] == 0) {
				DFS(r+1, c+1, 3);
			}
		}
		
		// 현재 세로라면 (2)
		if (dir == 2) {
			// 세로로 가 (r+1, c)
			if (r+1 >= 0 && c >= 0 && r+1 < N && c < N && map[r+1][c] == 0) {
				DFS(r+1, c, 2);
			}
			// 대각선으로 가
			if (r+1 >= 0 && c+1 >= 0 && r+1 < N && c+1 < N && map[r+1][c+1] == 0 && map[r][c+1] == 0 && map[r+1][c] == 0) {
				DFS(r+1, c+1, 3);
			}
		}
		
		
		// 현재 대각선이라면 (3)
		if (dir == 3) {
			// 가로로 가
			if (r >= 0 && c+1 >= 0 && r < N && c+1 < N && map[r][c+1] == 0) {
				DFS(r, c+1, 1);
			}
			// 세로로 가
			if (r+1 >= 0 && c >= 0 && r+1 < N && c < N && map[r+1][c] == 0) {
				DFS(r+1, c, 2);
			}
			// 대각선으로 가
			if (r+1 >= 0 && c+1 >= 0 && r+1 < N && c+1 < N && map[r+1][c+1] == 0 && map[r][c+1] == 0 && map[r+1][c] == 0) {
				DFS(r+1, c+1, 3);
			}
		}
	}
}
