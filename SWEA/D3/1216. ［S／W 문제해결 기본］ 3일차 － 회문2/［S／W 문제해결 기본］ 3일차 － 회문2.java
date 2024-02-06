import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		for (int t = 1; t <= 10; t++) {
			br.readLine();

			char[][] arr = new char[100][100];

			for (int r = 0; r < 100; r++) {
				String str = br.readLine();
				for (int c = 0; c < 100; c++) {
					arr[r][c] = str.charAt(c);
				}
			}

			int maxLen = 1;

			// 행 검사
			Loop1: for (int r = 0; r < 100; r++) {
				Loop2: for (int c = 0; c < 100; c++) {
					Loop3: for (int len = 100; len >= 2; len--) {
						if (c + len <= 100) {
							int end = c + len - 1;
							for (int i = c; i < c + len / 2; i++) {
								if (arr[r][i] != arr[r][end]) {
									continue Loop3;

								} else {
									--end;
								}
							}
							if (len > maxLen) {
								maxLen = len;
							}
						}
					}
				}
			}

			// 열 검사
			Loop1: for (int r = 0; r < 100; r++) {
				Loop2: for (int c = 0; c < 100; c++) {
					Loop3: for (int len = 100; len >= 2; len--) {
						if (r + len <= 100) {
							int end = r + len - 1;
							for (int i = r; i < r + len / 2; i++) {
								if (arr[i][c] != arr[end][c])
									continue Loop3;
								else {
									--end;
								}
							}
							if (len > maxLen) {
								maxLen = len;
							}
						}
					}
				}
			}

			System.out.println("#" + t + " " + maxLen);
		}
	}

}
