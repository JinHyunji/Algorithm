import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        ArrayList<Integer> times = new ArrayList<>();

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            times.add(Integer.parseInt(st.nextToken()));
        }

        Collections.sort(times);

        int ans = 0;
        int prevSum = 0;

        for (int i : times) {
            ans += prevSum + i;
            prevSum += i;
        }

        System.out.println(ans);
    }
}