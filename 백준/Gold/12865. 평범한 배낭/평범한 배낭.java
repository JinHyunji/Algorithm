import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken()); // 최대 가치

        int[][] things = new int[N + 1][2]; // 물건의 무게와 가치를 저장할 배열
        int[][] dp = new int[N + 1][K + 1]; // DP 테이블

        // 물건의 무게와 가치 입력
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            things[i][0] = Integer.parseInt(st.nextToken()); // 무게
            things[i][1] = Integer.parseInt(st.nextToken()); // 가치
        }

        // DP를 통해 최대 가치 계산
        for (int i = 1; i <= N; i++) { // 배낭에 넣을지 말지 결정할 물건
            for (int j = 1; j <= K; j++) { // 가치
                // 현재 물건을 가방에 담을 수 있을 때와 담을 수 없을 때를 비교하여 최대 가치 갱신
                if (things[i][0] <= j) {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - things[i][0]] + things[i][1]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // 결과 출력
        System.out.println(dp[N][K]);
    }
}
