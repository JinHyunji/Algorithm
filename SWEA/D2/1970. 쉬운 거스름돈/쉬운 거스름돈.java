import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int money;
		int[] dp;

		int T = Integer.parseInt(br.readLine());

		for (int t = 1; t <= T; t++) {
			sb.append("#" + t).append("\n");

			money = Integer.parseInt(br.readLine()) / 10;
			dp = new int[8];

			while (money != 0) {
				if (money / 5000 > 0) {
					dp[0] = money / 5000;
					money -= 5000 * dp[0];
				}
				if (money / 1000 > 0) {
					dp[1] = money / 1000;
					money -= 1000 * dp[1];
				}
				if (money / 500 > 0) {
					dp[2] = money / 500;
					money -= 500 * dp[2];
				}
				if (money / 100 > 0) {
					dp[3] = money / 100;
					money -= 100 * dp[3];
				}
				if (money / 50 > 0) {
					dp[4] = money / 50;
					money -= 50 * dp[4];
				}
				if (money / 10 > 0) {
					dp[5] = money / 10;
					money -= 10 * dp[5];
				}
				if (money / 5 > 0) {
					dp[6] = money / 5;
					money -= 5 * dp[6];
				}
				if (money / 1 > 0) {
					dp[7] = money / 1;
					money -= 1 * dp[7];
				}
			}
			for (int i = 0; i < 8; i++) {
				sb.append(dp[i] + " ");
			}
			sb.append("\n");
		}
		System.out.println(sb);
	}
}