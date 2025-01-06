
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int answer = 0;
        int[] remainders = new int[42];

        for (int i = 0; i < 10; i++) {
            int num = Integer.parseInt(br.readLine());

            remainders[num % 42]++;
        }

        for (int i : remainders) {
            if (i != 0) answer++;
        }

        System.out.println(answer);
    }
}