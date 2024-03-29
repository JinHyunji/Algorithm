import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Solution {

	static int[][] data; // 점수, 칼로리
	static int N, L, cal, score, max; // 재료수, 제한칼로리, 카운트, 최대값, 정답
	static boolean[] sel; // 사용된 값

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		int T = Integer.parseInt(br.readLine());

		for (int t = 1; t <= T; t++) {
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			L = Integer.parseInt(st.nextToken());
			data = new int[N][N];
			sel = new boolean[N];
			max = 0;
			
			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				data[i][0] = Integer.parseInt(st.nextToken());
				data[i][1] = Integer.parseInt(st.nextToken());
			}
			powerset(0);

			System.out.println("#" + t + " " + max);
		}
	}

	public static void powerset(int idx) {
		// base case : 재귀를 빠져나갈 조건
		if (idx >= N) {
			cal = 0;
			score = 0;
			for (int i = 0; i < N; i++) {
				if (sel[i]) {
					cal += data[i][1];
					score += data[i][0];
				}
			}
			if (0 < cal && cal <= L) {
				if (score > max)
					max = score;
			}
		} else {
			// recursive case : 나 자신을 다시 호출하는 부분
			// 이번 데이터 넣었어!
			sel[idx] = true;
			powerset(idx + 1); // 다음 데이터 판단 해줘

			// 이번 데이터 안 넣었어!
			sel[idx] = false;
			powerset(idx + 1); // 다음 데이터 판단 해줘
		}

	}

}
