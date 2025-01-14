
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int K = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());

        int[] lans = new int[K]; // 주어진 랜선 길이 저장
        long max = 0; // 랜선의 최대 길이 저장

        for (int i = 0; i < K; i++) {
            lans[i] = Integer.parseInt(br.readLine());
            max = Math.max(max, lans[i]);
        }

        long min = 1; // 랜선의 최소 길이
        long result = 0; // 최적의 랜선 길이

        while (min <= max) {
            long mid = (min + max) / 2;
            int cnt = 0;

            for (int lan : lans) {
                cnt += (lan / mid);
            }

            if (cnt >= N) { // 만들 수 있는 수가 많다면
                result = mid; // 현재 길이 저장
                min = mid + 1; // 랜선 최소 길이 늘리기
            } else {
                max = mid - 1;
            }
        }

        System.out.println(result);
    }
}