import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Solution {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int N, K;
		ArrayList<Character> list;
		ArrayList<Integer> result;

		int T = Integer.parseInt(br.readLine());

		for (int t = 1; t <= T; t++) {
			list = new ArrayList<>();
			result = new ArrayList<>();
			st = new StringTokenizer(br.readLine());

			// 값 입력 받기
			N = Integer.parseInt(st.nextToken());
			K = Integer.parseInt(st.nextToken());
			String input = br.readLine();

			// 리스트에 16진수 담기
			for (int i = input.length() - 1; i >= 0; i--) {
				char c = input.charAt(i);
				list.add(c);
			}

			// 세 번 반복 : 3회전 시 조합이 같아짐
			for (int i = 0; i < N/4; i++) {
				char tmp = list.get(0); // 맨 앞의 값 저장 : 뒤로 보내기 위함

				// 네 번 반복 : 네 번에 걸쳐 숫자 조합 만들기
				for (int j = N - 1; j >= N / 4 - 1; j -= N / 4) {
					String str = "";
					for (int k = j; k > j - N / 4; k--) {
						str += list.get(k);
					}
					int deci = Integer.parseInt(str, 16);
					if (result.contains(deci))
						continue;
					result.add(deci);
				}
				list.remove(0);
				list.add(tmp);
			}

			Collections.sort(result, Collections.reverseOrder());

			System.out.println("#" + t + " " + result.get(K - 1));
		}
	}
}