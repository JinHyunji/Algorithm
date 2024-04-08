import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {

	static int N, K, longer, max;
	static int[][] map;
	static boolean[][] visited;
	static int[] dr = { -1, 1, 0, 0 };
	static int[] dc = { 0, 0, -1, 1 };

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();

		int T = Integer.parseInt(br.readLine());

		for (int t = 1; t <= T; t++) {
			sb.append("#" + t + " ");
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			K = Integer.parseInt(st.nextToken());
			map = new int[N][N];
			visited = new boolean[N][N];
			longer = 0; // 최고 봉우리
			max = 0; // 최대 길이

			for (int r = 0; r < N; r++) {
				st = new StringTokenizer(br.readLine());
				for (int c = 0; c < N; c++) {
					map[r][c] = Integer.parseInt(st.nextToken());
					if (map[r][c] > longer) // 최고 봉우리 크기 찾기
						longer = map[r][c];
				}
			}

			for (int r = 0; r < N; r++) {
				for (int c = 0; c < N; c++) {
					if (map[r][c] == longer) { // 최고 봉우리면
						visited[r][c] = true;
						DFS(r, c, 1, 0);
						visited[r][c] = false;
					}
				}
			}
			sb.append(max).append("\n");
		}
		System.out.println(sb);
	}

	private static void DFS(int r, int c, int dist, int k) {
		if (dist > max)
			max = dist;

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr >= 0 && nc >= 0 && nr < N && nc < N && !visited[nr][nc]) {
				if (map[nr][nc] < map[r][c]) {
					visited[nr][nc] = true;
					DFS(nr, nc, dist + 1, k);
					visited[nr][nc] = false;
				} else {
					if (k == 0 && map[nr][nc] - K < map[r][c]) {
						int tmp = map[nr][nc]-map[r][c] + 1;
						map[nr][nc] -= tmp;
						visited[nr][nc] = true;
						DFS(nr, nc, dist + 1, 1);
						visited[nr][nc] = false;
						map[nr][nc] += tmp;
					}
				}
			}
		}
	}
}
