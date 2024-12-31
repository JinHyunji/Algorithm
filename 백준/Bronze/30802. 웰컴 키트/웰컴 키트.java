
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());

        int[] sizes = new int[6];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 6; i++) {
            sizes[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        int T = Integer.parseInt(st.nextToken());
        int P = Integer.parseInt(st.nextToken());

        int answer = 0;

        for (int size : sizes) {
            if (size == 0) continue;
            if (size <= T) {
                ++answer;
            } else {
                if (size % T == 0) {
                    answer += (size / T);
                } else {
                    answer += (size / T) + 1;
                }
            }
        }

        sb.append(answer).append("\n").append(N/P + " " + N%P);

        System.out.println(sb);
    }
}
