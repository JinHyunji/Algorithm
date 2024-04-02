import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {

	static class Swim {
		int r, c, time;

		public Swim(int r, int c, int time) {
			this.r = r;
			this.c = c;
			this.time = time;
		}
	}

	static int N, result;
	static int[][] ocean, count;
	static int[] start, end;
	static int[] dr = { -1, 1, 0, 0 };
	static int[] dc = { 0, 0, -1, 1 };
	static StringBuilder sb;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		sb = new StringBuilder();

		int T = Integer.parseInt(br.readLine());

		for (int t = 1; t <= T; t++) {
			N = Integer.parseInt(br.readLine());
			ocean = new int[N][N];
			count = new int[N][N];
			start = new int[2];
			end = new int[2];
			result = Integer.MAX_VALUE;
			sb.append("#" + t + " ");

			// 바다 상태 정보
			for (int r = 0; r < N; r++) {
				st = new StringTokenizer(br.readLine());
				for (int c = 0; c < N; c++) {
					ocean[r][c] = Integer.parseInt(st.nextToken());
				}
			}

			// 시작점과 도착점
			st = new StringTokenizer(br.readLine());
			start[0] = Integer.parseInt(st.nextToken());
			start[1] = Integer.parseInt(st.nextToken());

			st = new StringTokenizer(br.readLine());
			end[0] = Integer.parseInt(st.nextToken());
			end[1] = Integer.parseInt(st.nextToken());

			Queue<Swim> q = new LinkedList<>();

			q.add(new Swim(start[0], start[1], 0));

			while (!q.isEmpty()) {
				Swim s = q.poll();
				ocean[s.r][s.c] = 1;
				
				if (s.r == end[0] && s.c == end[1] && s.time < result) {
					result = s.time;
					break;
				}

				for (int i = 0; i < 4; i++) {
					int nr = s.r + dr[i];
					int nc = s.c + dc[i];

					if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
						if (ocean[nr][nc] == 0) {
							q.add(new Swim(nr, nc, s.time + 1));
						} else if (ocean[nr][nc] == 2) {
							if (s.time % 3 == 2) {
								q.add(new Swim(nr, nc, s.time + 1));
							} else {
								q.add(new Swim(s.r, s.c, s.time + 1));
							}
						}
					}
				}
			}

			if (result == Integer.MAX_VALUE)
				result = -1;

			sb.append(result).append("\n");
		}
		
		System.out.println(sb);
	}
}