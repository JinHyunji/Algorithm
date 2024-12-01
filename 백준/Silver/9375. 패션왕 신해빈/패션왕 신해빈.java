import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());
        int n;

        for (int t = 1; t <= T; t++) {
            n = Integer.parseInt(br.readLine());

            HashMap<String, Integer> map = new HashMap<>();

            String name;
            String type;

            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                name = st.nextToken();
                type = st.nextToken();

                if (map.containsKey(type)) {
                    map.replace(type, map.get(type) + 1);
                } else {
                    map.put(type, 1);
                }
            }

            int sum = 1;

            for (Integer i : map.values()) {
                sum *= (i + 1);
            }

            sum -= 1;
            sb.append(sum).append("\n");
        }

        System.out.println(sb);
    }
}
