import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static boolean[] prime;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int M = Integer.parseInt(st.nextToken());
		int N = Integer.parseInt(st.nextToken());

		check(N);

		for (int i = M; i < prime.length; i++) {
			if (prime[i] == false) {
				System.out.println(i);
			}
		}
	}

	private static void check(int n) {
		prime = new boolean[n + 1];
		
		if (n < 2) return;
		
		prime[0] = prime[1] = true;
		
		for (int i = 2; i <= Math.sqrt(n); i++) {
			if (prime[i] == true) continue;

			for (int j = i * i; j < prime.length; j = j+i) {
				prime[j] = true;
			}
		}
	}
}