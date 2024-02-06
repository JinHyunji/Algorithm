import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(br.readLine());
		
		Loop1: for (int t = 1; t <= T; t++) {
			char[] arr = br.readLine().toCharArray();
			
			for (int i = 0; i < arr.length; i++) {
				if (arr[i] != arr[arr.length -1 -i]) {
					System.out.println("#" + t + " " + 0);
					continue Loop1;
				}
			}
			System.out.println("#" + t + " " + 1);
		}
		
	}

}