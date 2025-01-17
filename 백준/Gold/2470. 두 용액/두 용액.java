import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[] liquid = new int[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            liquid[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(liquid); // 오름차순 정렬

        int[] result = new int[2];
        int start = 0; // 시작 포인터 위치
        int end = N - 1; // 끝 포인터 위치
        int min = 2000000000; // 두 용액의 합의 절대값의 최소

        while (start < end) {
            int absSum = Math.abs(liquid[start] + liquid[end]);
            if (liquid[start] + liquid[end] < 0) {
                if (absSum < min) {
                    result[0] = liquid[start];
                    result[1] = liquid[end];
                    min = absSum;
                }
                start += 1;
            } else if (liquid[start] + liquid[end] > 0) {
                if (absSum < min) {
                    result[0] = liquid[start];
                    result[1] = liquid[end];
                    min = absSum;
                }
                end -= 1;
            } else {
                result[0] = liquid[start];
                result[1] = liquid[end];
                break;
            }
        }

        Arrays.sort(result);

        System.out.println(result[0] + " " + result[1]);
    }
}