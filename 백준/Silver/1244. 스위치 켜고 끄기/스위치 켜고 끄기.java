import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine()); // 스위치 개수
		int[] switchs = new int[N + 1]; // 스위치 온오프 체크

		StringTokenizer st = new StringTokenizer(br.readLine());

		for (int i = 1; i <= N; i++) {
			switchs[i] = Integer.parseInt(st.nextToken());
		}
		
		int S = Integer.parseInt(br.readLine());

		for (int i = 0; i < S; i++) {
			st = new StringTokenizer(br.readLine());

			int gender = Integer.parseInt(st.nextToken());
			int num = Integer.parseInt(st.nextToken());

			if (gender == 1) { // 남자라면
				for (int j = 1; j <= N; j++) {
					if (j % num == 0) { // num의 배수 자리에 스위치 바꿔주기
						if (switchs[j] == 1)
							switchs[j] = 0;
						else
							switchs[j] = 1;
					}
				}
			} else { // 여자라면
				// num 자리 스위치 바꾸기
				if (switchs[num] == 1)
					switchs[num] = 0;
				else
					switchs[num] = 1;
				
				int j = 1; // 칸 이동만큼 곱해줄 변수
				
				// 인덱스 범위 안에 있고 값이 서로 같을 때 반복
				while (true) {
					// 양 옆으로 한 칸 이동
					int f = num - (1 * j); // 한 칸 앞 초기화
					int b = num + (1 * j++); // 한 칸 뒤 초기화
					
					
					if (f < 1 || b > N || switchs[f] != switchs[b]) break;
					
					if (switchs[f] == 1) {
						switchs[f] = 0;
						switchs[b] = 0;
					} else {
						switchs[f] = 1;
						switchs[b] = 1;
					}
				}
			}
		}
		
		for (int i = 1; i <= N; i++) {
			if (i == 21 || i == 41 || i == 61 || i == 81)
				System.out.println();
			System.out.print(switchs[i] + " ");
		}
	}
}
