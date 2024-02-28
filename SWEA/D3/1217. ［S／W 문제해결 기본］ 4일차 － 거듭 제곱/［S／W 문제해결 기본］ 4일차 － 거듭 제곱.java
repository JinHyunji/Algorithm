import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		for (int t = 1; t < 11; t++) {
			br.readLine();
			st = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());
			
			System.out.println("#" + t + " " + pow(N, M));
		}
	}

	static int pow(int n, int m) {
		if (m == 1) return n;
		return n * pow(n, m-1);
	}
}