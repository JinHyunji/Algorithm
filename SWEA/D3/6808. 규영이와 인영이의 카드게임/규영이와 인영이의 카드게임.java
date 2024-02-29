import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {

	static int[] data_k, data_e;
	static boolean[] card;
	static int N = 9;
	static int sum_k, sum_e, win, lose;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		int T = Integer.parseInt(br.readLine());

		for (int t = 1; t <= T; t++) {
			data_k = new int[9];
			data_e = new int[9];
			card = new boolean[19];
			win = 0;
			lose = 0;
			sum_k = 0;
			sum_e = 0;
			
			st = new StringTokenizer(br.readLine());

			// 카드 담기
			// 규영
			for (int i = 0; i < 9; i++) {
				int k = Integer.parseInt(st.nextToken());
				card[k] = true;
				data_k[i] = k;
			}
			// 인영
			for (int i = 1, j = 0; i < 19; i++) {
				if (card[i] == false) {
					data_e[j++] = i;
				}
			}
			
			perm(0);
			
			System.out.println("#" + t + " " + win + " " + lose);
		}
	}

	public static void perm(int idx) {
		// 기저조건
		if (idx == N) {
			for (int i = 0; i < 9; i++) {
				if (data_k[i] > data_e[i]) {
					sum_k += data_k[i] + data_e[i];;
				} else {
					sum_e +=  data_k[i] + data_e[i];
				}
			}
			if (sum_k > sum_e) {
				win++;
			} else {
				lose++;
			}
			sum_k = 0;
			sum_e = 0;
			return;
		}

		// 재귀조건
		for (int i = idx; i < N; i++) {
			swap(i, idx);
			perm(idx + 1);
			swap(i, idx);
		}
	}

	public static void swap(int a, int b) {
		int tmp = data_e[a];
		data_e[a] = data_e[b];
		data_e[b] = tmp;
	}

}
