import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int N, K, cnt;
    static ArrayList<Integer> prices = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        cnt = 0;

        for (int i = 0; i < N; i++) {
            prices.add(Integer.parseInt(br.readLine()));
        }

        Collections.sort(prices, Collections.reverseOrder());

        for (int i : prices) {
            if ((K / i) != 0) {
                cnt += K / i;
                K %= i;
            }
        }

        System.out.println(cnt);
    }
}