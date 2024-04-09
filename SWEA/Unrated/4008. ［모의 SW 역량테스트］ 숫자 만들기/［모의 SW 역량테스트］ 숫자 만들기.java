import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {

    static int N, max, min;
    static int[] op, result, nums;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());

        for (int t = 1; t <= T; t++) {
            sb.append("#" + t + " ");
            N = Integer.parseInt(br.readLine()); // 숫자의 개수
            max = Integer.MIN_VALUE;
            min = Integer.MAX_VALUE;
            op = new int[4]; // 연산자 담기
            result = new int[N - 1];
            nums = new int[N]; // 숫자 담기

            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < 4; i++) {
                op[i] = Integer.parseInt(st.nextToken());
            }

            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < N; i++) {
                nums[i] = Integer.parseInt(st.nextToken());
            }

            calculate(0, nums[0]);

            sb.append(max - min).append("\n");
        }
        System.out.println(sb);
    }

    private static void calculate(int depth, int result) {
        if (depth == N - 1) {
            max = Math.max(max, result);
            min = Math.min(min, result);
            return;
        }

        for (int i = 0; i < 4; i++) {
            if (op[i] > 0) {
                op[i]--;
                int nextResult = performOperation(result, nums[depth + 1], i);
                calculate(depth + 1, nextResult);
                op[i]++;
            }
        }
    }

    private static int performOperation(int a, int b, int operator) {
        switch (operator) {
            case 0:
                return a + b;
            case 1:
                return a - b;
            case 2:
                return a * b;
            case 3:
                return a / b;
            default:
                return 0;
        }
    }
}
