import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int N;
		int M;
		
		for (int t = 1; t <= 10; t++) {
			br.readLine();
			st = new StringTokenizer(br.readLine());
			
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			
			System.out.println("#" + t + " " + pow(N, M));
		}
	}
	
	public static int pow(int N, int M) {
		if (M == 0) return 1;
		return N * pow(N, M-1);
	}
}
