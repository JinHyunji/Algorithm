import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static class Tomato {
		int r,c,day;

		public Tomato(int r, int c, int day) {
			this.r = r;
			this.c = c;
			this.day = day;
		}
	}
	
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
		Queue<Tomato> q = new LinkedList<>();
		
		for (int r = 0; r < N; r++) {
			st = new StringTokenizer(br.readLine());
			for (int c = 0; c < M; c++) {
				int a = Integer.parseInt(st.nextToken());
				if (a == 1) {
					q.add(new Tomato(r,c,0));
				}
				map[r][c] = a;
			}
		}

		while(!q.isEmpty()) {
			Tomato tomato = q.poll();
			count = tomato.day;
			
			for (int i = 0; i < 4; i++) {
				int nr = tomato.r + dr[i];
				int nc = tomato.c + dc[i];
				
				if (nr >= 0 && nc >= 0 && nr < N && nc < M && map[nr][nc] == 0) {
					q.add(new Tomato(nr, nc, tomato.day+1));
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
