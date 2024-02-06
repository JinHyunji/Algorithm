import java.util.Scanner;

public class Solution {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();

		for (int t = 1; t <= T; t++) {
			int N = sc.nextInt();

			int[] dr = { 0, 1, 0, -1 };
			int[] dc = { 1, 0, -1, 0 };

			int[][] arr = new int[N][N];

			int num = 1;

			int sR = 0;
			int sC = 0;
			arr[sR][sC] = num++;
			int d = 0;
			
			while (num <= N*N) {
				sR += dr[d];
				sC += dc[d];
				
				if (sR < 0 || sR > N-1 || sC < 0 || sC > N-1 || arr[sR][sC] != 0) {
					sR -= dr[d];
					sC -= dc[d];
					d = (d+1) % 4;
					continue;
				}
				arr[sR][sC] = num++;
			}
			
			System.out.println("#" + t);
			for (int r = 0; r < arr.length; r++) {
				for (int c = 0; c < arr[r].length; c++) {
					System.out.print(arr[r][c] + " ");
				}
				System.out.println();
			}

		}

	}

}
