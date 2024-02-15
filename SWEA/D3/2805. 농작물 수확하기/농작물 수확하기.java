import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		int[][] map;
		int answer;
		
		int T = Integer.parseInt(br.readLine()); // 테스트 케이스 입력

		for (int t = 1; t <= T; t++) {
			// 농장 크기 입력
			int N = Integer.parseInt(br.readLine());
			answer = 0;
			
			// 농장 배열 생성
			map = new int[N][N];

			// 농장 수익 초기화
			for (int r = 0; r < N; r++) {
				String input = br.readLine();
				for (int c = 0; c < N; c++) {
					map[r][c] = input.charAt(c) - '0';
				}
			}
			
			for (int r = 0; r < N; r++) {
				int start = Math.abs(N/2 - r);
				for (int c = start; c < N - start; c++) {
					answer += map[r][c];
				}
			}
			
			System.out.println("#" + t + " " + answer);
		}
	}
}
