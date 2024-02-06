import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		for (int t = 1; t < 11; t++) {
			int d = Integer.parseInt(br.readLine());
			int[] high = new int[100];

			int answer = 0;

			StringTokenizer st = new StringTokenizer(br.readLine());

			for (int i = 0; i < 100; i++) {
				high[i] = Integer.parseInt(st.nextToken());
			}

			// 덤프 횟수가 0보다 클 때만 반복
			while (d >= 0) {
				int max = 1, min = 100;
				int maxIdx = 0, minIdx = 0;

				// 최고 높이, 최저 높이, 각각의 인덱스 구하기
				for (int i = 0; i < 100; i++) {
					if (high[i] > max) {
						max = high[i];
						maxIdx = i;
					}
					if (high[i] < min) {
						min = high[i];
						minIdx = i;
					}
				}
				
				// 덤프 횟수가 0이면 최고점과 최저점의 높이 차 반환
				if (d == 0) {
					answer = high[maxIdx] - high[minIdx];
					break;
				}
				
				// 주어진 덤프 횟수 내에서 평턴화가 완료되면 높이 차 반환
				if (high[maxIdx] - high[minIdx] == 0 || high[maxIdx] - high[minIdx] == 1) {
					answer = high[maxIdx] - high[minIdx];
					break;
				} 
				
				// 상자 개수 및 덤프 횟수 증감
				--high[maxIdx];
				++high[minIdx];
				--d;
				
			}

			System.out.println("#" + t + " " + answer);
		}
	}
}
