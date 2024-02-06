import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Solution {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for (int t = 1; t <= 10; t++) {
			int N = Integer.parseInt(br.readLine());
			
			StringTokenizer st = new StringTokenizer(br.readLine());

			int[] arr = new int[N];
			int count = 0;

			// 배열 초기화
			for (int i = 0; i < N; i++) {
				arr[i] = Integer.parseInt(st.nextToken());
			}

			for (int i = 2; i < N - 2; i++) { // 0을 제외한 빌딩의 수만큼 반복
				// 해당 인덱스를 기준으로 양 옆으로 2칸씩 비교
				if (arr[i-1] < arr[i] && arr[i-2] < arr[i] && arr[i] > arr[i+1] && arr[i] > arr[i+2]) {
					List<Integer> list = new ArrayList<>();
					list.add(arr[i-1]);
					list.add(arr[i-2]);
					list.add(arr[i+1]);
					list.add(arr[i+2]);
					count += (arr[i] - Collections.max(list));
				}
				else {
					continue;
				}
				
			}
			
			System.out.println("#" + t + " " + count);
		}
	}
}
