import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N, M, year;
	static int[][] map;
	static boolean[][] visited;
	static int[] dr = { -1, 1, 0, 0 };
	static int[] dc = { 0, 0, -1, 1 };

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		year = 0;
		map = new int[N][M];

		for (int r = 0; r < N; r++) {
			st = new StringTokenizer(br.readLine());
			for (int c = 0; c < M; c++) {
				map[r][c] = Integer.parseInt(st.nextToken());
			}
		}

		while (true) {
			++year;

			// 얼음 녹이기
			int[][] tempMap = new int[N][M];
            for (int n = 0; n < N; n++) {
                for (int m = 0; m < M; m++) {
                    tempMap[n][m] = map[n][m];
                }
            }
            
			for (int r = 1; r < N - 1; r++) {
				for (int c = 1; c < M - 1; c++) {
					if (map[r][c] != 0) {
						int seaCnt = 0;
						for (int i = 0; i < 4; i++) {
							int nr = r + dr[i];
							int nc = c + dc[i];

							if (map[nr][nc] == 0) {
								seaCnt++;
							}
						}
						tempMap[r][c] = Math.max(0, map[r][c] - seaCnt);
					}
				}
			}

			 map = tempMap;
			// 모두 녹았는지 확인
			if (isAllMelted()) {
				year = 0;
				break;
			}

			// 분리되었는지 확인
			visited = new boolean[N][M];
			boolean foundIceberg = false;
			boolean separated = false;
			
			for (int n = 1; n < N-1; n++) {
				for (int m = 1; m < M-1; m++) {
					if (map[n][m] != 0 && !visited[n][m]) {
						if (foundIceberg) {
							separated = true;
							break;
						}
						check(n, m);
						foundIceberg = true;
					}
				}
				
				if (separated)
					break;
			}
			
			if (separated)
				break;

		}

		System.out.println(year);
	}

	

	private static void check(int r, int c) {
		visited[r][c] = true;
		
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			
			if (nr >= 0 && nc >= 0 && nr < N && nc < M && !visited[nr][nc] && map[nr][nc] != 0) {
				check(nr, nc);
			}
		}
	}



	private static boolean isAllMelted() {
		for (int r = 1; r < N - 1; r++) {
			for (int c = 1; c < M - 1; c++) {
				if (map[r][c] != 0)
					return false;
			}
		}
		return true;
	}
}