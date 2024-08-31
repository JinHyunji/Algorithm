import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N, ans;
        N = Integer.parseInt(br.readLine());
        ans = 0;
        ArrayList<Integer> times = new ArrayList<>();

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            times.add(Integer.parseInt(st.nextToken()));
        }

        Collections.sort(times);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= i; j++) {
                ans += times.get(j);
            }
        }
        
        System.out.println(ans);
    }
}