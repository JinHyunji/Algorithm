import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }
        StringBuffer sb = new StringBuffer();
        Stack<Integer> stack = new Stack<>();
        int num = 1;
        boolean print = false;

        for (int i = 0; i < N; i++) {
            if (A[i] >= num) {
                while (A[i] >= num) {
                    stack.push(num++);
                    sb.append("+\n");
                }
                stack.pop();
                sb.append("-\n");
            } else {
                int pop = stack.pop();
                if (pop > A[i]) {
                    System.out.println("NO");
                    print = true;
                    break;
                } else sb.append("-\n");
            }
        }
        if (!print) System.out.println(sb.toString());
    }
}