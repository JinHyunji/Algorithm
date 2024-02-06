import java.util.Scanner;
import java.util.Stack;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int k = sc.nextInt();
		Stack<Integer> s = new Stack<>();
		int sum = 0;

		for (int i = 0; i < k; i++) {
			int input = sc.nextInt();

			if (s.isEmpty()) {
				s.push(input);
				continue;
			}
				
			if (input == 0)
				s.pop();
			else s.push(input);
		}

		while (!s.isEmpty()) {
			sum += s.pop();
		}
		
		System.out.println(sum);

	}

}
