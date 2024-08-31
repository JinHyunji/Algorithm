import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

    static int N, M;
    static String tempNum, tempInput;
    static HashMap<String, String> bookByNum = new HashMap<>();
    static HashMap<String, String> bookByStr = new HashMap<>();
    static StringBuffer sb = new StringBuffer();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for (int i = 1; i <= N; i++) {
            tempNum = i + "";
            tempInput = br.readLine();
            bookByNum.put(tempNum, tempInput);
            bookByStr.put(tempInput, tempNum);
        }


        for (int i = 0; i < M; i++) {
            String input = br.readLine();
            if (bookByNum.containsKey(input)) {
                sb.append(bookByNum.get(input)).append("\n");
            } else if (bookByStr.containsKey(input)) {
                sb.append(bookByStr.get(input)).append("\n");
            }
        }

        System.out.println(sb);
    }
}