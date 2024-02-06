import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {
		// 수열의 길이 입력받고 배열 생성
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int[] arr = new int[N];

		// 수열의 길이만큼 숫자 입력 받아 배열에 저장
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		// 가장 긴 길이
		int max = 0;

		// DP 사용을 위한 오름차, 내림차 순 배열 생성
		int[] dpASC = new int[N];
		int[] dpDES = new int[N];

		dpASC[0] = 1; // 인덱스 0을 1로 초기화
		dpDES[0] = 1;

		// 오름차순 비교
		for (int i = 0; i < N - 1; i++) {
			dpASC[i+1] = dpASC[i] + 1;
			if (arr[i] > arr[i + 1]) {
				dpASC[i+1] = 1;
			}
		}
		
		// 내림차순 비교
		for (int i = 0; i < N - 1; i++) {
			dpDES[i+1] = dpDES[i] + 1;
			if (arr[i] < arr[i + 1]) {
				dpDES[i+1] = 1;
			}
		}
        
        // dp 배열에서 최대값 찾기 
		for (int i = 0; i < N; i++) {
			if (dpASC[i] > max) max = dpASC[i];
			if (dpDES[i] > max) max = dpDES[i];
		}
		
        // 최대값 출력
		System.out.println(max);
	}

}
