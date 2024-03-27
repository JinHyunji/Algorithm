import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {


	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int[][] result;
		int N;
		
		int T = Integer.parseInt(br.readLine());

		for (int t = 0; t < T; t++) {
			N = Integer.parseInt(br.readLine());

			if (N == 0) {
				System.out.println(1 + " " + 0);
				continue;
			}
			
			if (N == 1) {
				System.out.println(0 + " " + 1);
				continue;
			}
			
			result = new int[2][N+1];
			
			result[0][0] = 1;
			result[1][1] = 1;
			
			for (int i = 2; i <= N; i++) {
				result[0][i] += (result[0][i-2] + result[0][i-1]);
				result[1][i] += (result[1][i-2] + result[1][i-1]);
			}
			
			System.out.println(result[0][N] + " " + result[1][N]);
		}
	}
}
