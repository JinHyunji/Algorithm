import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

public class Solution {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		Map<Character, Integer> priority = new HashMap<>();
		priority.put('(', 0);
		priority.put('+', 1);
		priority.put('*', 2);

		String postfix;

		Stack<Character> op;
		Stack<Integer> od;

		int answer;

		for (int t = 1; t <= 10; t++) {
			int len = Integer.parseInt(br.readLine());
			String expression = br.readLine();
			char c;

			// 중위 표기식 -> 후위 표기식
			postfix = "";
			op = new Stack<>();

			for (int i = 0; i < len; i++) {
				c = expression.charAt(i);
				if (c == '(')
					op.push(c);
				else if (c == ')') {
					while (op.peek() != '(') {
						postfix += op.pop();
					}
					op.pop();
				} else if ('0' <= c && c <= '9')
					postfix += c;
				else {
					if (op.isEmpty())
						op.push(c);
					else {
						while (!op.isEmpty() && priority.get(c) <= priority.get(op.peek())) {
							postfix += op.pop();
						}
						op.push(c);
					}
				}

			}

			// 후위 표기식 -> 계산
			od = new Stack<>();
			int result;
			
			for (int i = 0; i < postfix.length(); i++) {
				c = postfix.charAt(i);

				if ('0' <= c && c <= '9')
					od.push(c - '0');
				else {
					int B = od.pop();
					int A = od.pop();
					
					if (c == '*') 
						result = A * B;
					else 
						result = A + B;
					od.push(result);
					
				}
			}
			
			answer = od.pop();
			System.out.println("#" + t + " " + answer);
		}
	}
}
