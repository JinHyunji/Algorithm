import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int N, count;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		count = 0;
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			int n = Integer.parseInt(st.nextToken());
			
			check(n);
		}
		
		System.out.println(count);
	}

	private static void check(int n) {
		if (n == 1) return;
		
		for (int i = 2; i < n; i++) {
			if (n % i == 0) {
				return;
			}
		}
		
		count++;
	}
}
