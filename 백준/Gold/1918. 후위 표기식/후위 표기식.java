import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.Stack;

public class Main {
	public static void main(String[] args) {
		Map<Character, Integer> priority = new HashMap<>();

		priority.put('(', 0);
		priority.put('+', 1);
		priority.put('-', 1);
		priority.put('*', 2);
		priority.put('/', 2);

		Stack<Character> op = new Stack<>();

		Scanner sc = new Scanner(System.in);

		String expression = sc.next();
		String postfix = "";
		char c;
		
		for (int i = 0; i < expression.length(); i++) {
			c = expression.charAt(i);

			if (c == '(') {
				op.push(c);
			} else if ('A' <= c && c <= 'Z') {
				postfix += c;
			} else if (c == ')') {
				while (op.peek() != '(') {
					postfix += op.pop();
				}
				op.pop();
			} else {
				if (op.isEmpty()) {
					op.push(c);
				} else {
					while (!op.isEmpty() && priority.get(c) <= priority.get(op.peek())) {
						postfix += op.pop();
					}
					op.push(c);
				}
			}
		}
		
		while (!op.isEmpty()) postfix += op.pop();
		
		System.out.println(postfix);
	}
}
