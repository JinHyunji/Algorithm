import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static int[][] map;
	static int N, M, count;
	static int[] dr = { -1, 1, 0, 0 };
	static int[] dc = { 0, 0, -1, 1 };

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());

		map = new int[N][M];
		count = 0;
		Queue<int[]> q = new LinkedList<>();
		
		for (int r = 0; r < N; r++) {
			st = new StringTokenizer(br.readLine());
			for (int c = 0; c < M; c++) {
				int a = Integer.parseInt(st.nextToken());
				if (a == 1) {
					q.add(new int[] {r,c,0});
				}
				map[r][c] = a;
			}
		}

		while(!q.isEmpty()) {
			int[] tomato = q.poll();
			count = tomato[2];
			
			for (int i = 0; i < 4; i++) {
				int nr = tomato[0] + dr[i];
				int nc = tomato[1] + dc[i];
				
				if (nr >= 0 && nc >= 0 && nr < N && nc < M && map[nr][nc] == 0) {
					q.add(new int[] {nr,nc,tomato[2]+1});
					map[nr][nc] = 1;
				}
			}
		}
		
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < M; c++) {
				if (map[r][c] == 0) {
					System.out.println(-1);
					return;
				}
			}
		}

		System.out.println(count);
	}
}
