import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Solution {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int T = Integer.parseInt(br.readLine());

		for (int t = 1; t <= T; t++) {
			int K = Integer.parseInt(br.readLine());
			Stack<Integer> stack = new Stack<>();
			for (int k = 0; k < K; k++) {
				int call = Integer.parseInt(br.readLine());
				if (call == 0) {
					stack.pop();
				} else {
					stack.push(call);
				}
			}
			int sum = 0;
			while (!stack.isEmpty()) {
				sum += stack.pop();
			}
			System.out.println("#" + t + " " + sum);
		}
	}
}