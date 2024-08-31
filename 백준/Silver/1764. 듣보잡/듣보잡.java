import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int N, M;
    static String input;
    static ArrayList<String> answer = new ArrayList<>();
    static HashSet<String> sets = new HashSet<>();
    static StringBuffer sb = new StringBuffer();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for (int i = 0; i < N; i++) {
            sets.add(br.readLine());
        }

        for (int i = 0; i < M; i++) {
            input = br.readLine();
            if (sets.contains(input)) {
                answer.add(input);
            }
        }

        Collections.sort(answer);

        sb.append(answer.size()).append("\n");
        for (int i = 0; i < answer.size(); i++) {
            sb.append(answer.get(i)).append("\n");
        }

        System.out.println(sb);
    }
}