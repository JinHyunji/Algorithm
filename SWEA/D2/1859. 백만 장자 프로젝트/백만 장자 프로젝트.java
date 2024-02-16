import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		int T = Integer.parseInt(br.readLine());
		int[] arr;
		int[] maxList;
		Long profit;

		for (int t = 1; t <= T; t++) {
			int N = Integer.parseInt(br.readLine());
			arr = new int[N];
			maxList = new int[N];

			profit = 0L;
			int max = 0;
			st = new StringTokenizer(br.readLine());
			for (int n = 0; n < N; n++) {
				arr[n] = Integer.parseInt(st.nextToken());
			}

			for (int n = N - 1; n >= 0; n--) {
				if (arr[n] > max)
					max = arr[n];
				maxList[n] = max;
				profit += (maxList[n] - arr[n]);
			}
			
			System.out.println("#" + t + " " + profit);
		}
	}
}
