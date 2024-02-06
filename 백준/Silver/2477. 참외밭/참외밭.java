
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int K = Integer.parseInt(br.readLine());

		int[][] arr = new int[6][2];

		StringTokenizer st;

		int maxW = 0; // 가장 긴 가로
		int mwIdx = 0; // 가로 인덱스
		int maxH = 0; // 가장 긴 세로
		int mhIdx = 0; // 세로 인덱스
		int emptyW = 0; // 빈 면적의 가로
		int emptyH = 0; // 빈 면적의 세로

		// 배열에 값 정리
		for (int r = 0; r < 6; r++) {
			st = new StringTokenizer(br.readLine());
			for (int c = 0; c < 2; c++) {
				arr[r][c] = Integer.parseInt(st.nextToken());
				if (arr[r][0] == 1 || arr[r][0] == 2) { // 세로 길이면
					if (arr[r][1] > maxH) {
						maxH = arr[r][1]; // 세로 최대값 넣기
						mhIdx = r;
					}
				} else { // 가로 길이면
					if (arr[r][1] > maxW) {
						maxW = arr[r][1]; // 가로 최대값 넣기
						mwIdx = r;
					}
				}
			}
		}

		// 빈 면적의 가로, 세로 구하기
		if (mwIdx == 0) {
			emptyW = Math.abs(arr[1][1] - arr[5][1]);
		} else if (0 < mwIdx && mwIdx < 5) {
			emptyW = Math.abs(arr[mwIdx - 1][1] - arr[mwIdx + 1][1]);
		} else {
			emptyW = Math.abs(arr[4][1] - arr[0][1]);
		}
		if (mhIdx == 0) {
			emptyH = Math.abs(arr[1][1] - arr[5][1]);
		} else if (0 < mhIdx && mhIdx < 5) {
			emptyH = Math.abs(arr[mhIdx - 1][1] - arr[mhIdx + 1][1]);
		} else {
			emptyH = Math.abs(arr[4][1] - arr[0][1]);
		}

		// 가장 큰 면적에서 빈 곳 면적 빼기
		int area = maxW * maxH - emptyW * emptyH;

		// 면적 * 참외 수
		System.out.println(area * K);
	}
}
