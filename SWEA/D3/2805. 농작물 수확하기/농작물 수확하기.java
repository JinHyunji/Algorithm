import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int answer;
		
		int T = Integer.parseInt(br.readLine()); // 테스트 케이스 입력

		for (int t = 1; t <= T; t++) {
			// 농장 크기 입력
			int N = Integer.parseInt(br.readLine());
			answer = 0;
			
			for (int r = 0; r < N; r++) {
				String input = br.readLine();
				int start = Math.abs(N/2 - r);
				for (int c = start; c < N - start; c++) {
					answer += (input.charAt(c) - '0');
				}
			}
			
			System.out.println("#" + t + " " + answer);
		}
	}
}
