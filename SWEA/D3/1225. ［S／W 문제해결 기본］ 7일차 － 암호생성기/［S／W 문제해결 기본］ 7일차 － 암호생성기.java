import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		Queue<Integer> q = new LinkedList<>();

		for (int t = 1; t <= 10; t++) {
			br.readLine();
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < 8; i++) {
				int input = Integer.parseInt(st.nextToken());
				q.offer(input);
			}

			start: while (true) {
				for (int cnt = 1; cnt <= 5; cnt++) {
					int v = q.poll() - cnt;
					if (v <= 0) {
						q.offer(0);
						break start;
					} else {
						q.offer(v);
					}
				}
			}

			System.out.print("#" + t + " ");
			while (!q.isEmpty()) {
				System.out.print(q.poll() + " ");
			}
			System.out.println();
		}
	}

}
