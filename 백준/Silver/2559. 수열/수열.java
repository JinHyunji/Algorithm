import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		// N, K 값 입력 받기
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());

		// 온도 입력 받은 뒤 배열에 순서대로 저장
		st = new StringTokenizer(br.readLine());
		int[] temp = new int[N];
		for (int i = 0; i < N; i++) {
			temp[i] = Integer.parseInt(st.nextToken());
		}

		int max = Integer.MIN_VALUE; // 온도 합 최대값
		int sum = 0; // 온도 합 비교 변수

		// 0부터 N-K까지 돌면서 시작점 변경해주기
		for (int i = 0; i <= N - K; i++) {
			for (int j = i; j < i + K; j++) {
				sum += temp[j];
			}
			if (sum > max)
				max = sum;
			sum = 0;
		}
		System.out.println(max);
	}

}
