
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());
        int[][] scores;

        for (int t = 0; t < T; t++) {
            String str = br.readLine();
            int answer = 0;
            scores = new int[2][str.length()];

            for (int i = 0; i < str.length(); i++) {
                char c = str.charAt(i);

                if (c == 'O') {
                    scores[0][i] = 1;
                    if (i == 0) {
                        scores[1][i] = 1;
                        continue;
                    }
                    if (scores[0][i - 1] == 1) scores[1][i] = scores[1][i - 1] + 1;
                    if (scores[0][i - 1] == 0) scores[1][i] = 1;
                }
            }

            for (int i = 0; i < str.length(); i++) {
                answer += scores[1][i];
            }

            sb.append(answer).append("\n");
        }

        System.out.println(sb);
    }
}