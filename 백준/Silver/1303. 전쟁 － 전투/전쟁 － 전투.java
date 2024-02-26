import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static int N, M, W, B, count; // 가로, 세로, 아군합, 적군합
	public static char[][] map;
	public static boolean[][] visited;
	public static int[] dr = { -1, 1, 0, 0 }; // 상 하 좌 우
	public static int[] dc = { 0, 0, -1, 1 }; // 상 하 좌 우

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken()); // 가로 열
		M = Integer.parseInt(st.nextToken()); // 세로 행
		map = new char[M][N]; // 전쟁터
		visited = new boolean[M][N]; // 방문 배열

		// 배열에 담기
		for (int r = 0; r < M; r++) {
			String input = br.readLine();
			for (int c = 0; c < N; c++) {
				map[r][c] = input.charAt(c);
			}
		}
		

		// 전체 탐색
		for (int r = 0; r < M; r++) {
			for (int c = 0; c < N; c++) {
				// 방문 안했다면
				if (visited[r][c] == false) {
					char ch = map[r][c];
					count = 0;
					DFS(r, c, ch);
					
					if (ch == 'W') {
						W += count * count;
					} else {
						B += count * count;
					}
					
				}
			}
		}

		System.out.println(W + " " + B);
	}

	public static void DFS(int r, int c, char ch) {
		visited[r][c] = true;
		count++;
		
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			
			if (nr >= 0 && nc >= 0 && nr < M && nc < N && map[nr][nc] == ch && visited[nr][nc] == false) {
				DFS(nr, nc, ch);
			}
		}
	}

}
