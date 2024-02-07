import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Solution {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		ArrayList<Integer> maxList;
		int[] count;
		int max;

		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			st = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());

			count = new int[N + M + 1];
			max = 0;
			maxList = new ArrayList<>();

			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= M; j++) {
					count[i + j]++;
				}
			}
			
			for (int i = 2; i < count.length; i++) {
				if (count[i] > max) max = count[i];
			}
			
			for (int i = 2; i < count.length; i++) {
				if (count[i] >= max) maxList.add(i);
			}
			
			System.out.print("#" + t + " ");
			for (int i : maxList) {
				System.out.print(i + " ");
			}
			System.out.println();
		}
	}

}
