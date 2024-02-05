import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int width = Integer.parseInt(st.nextToken()); // 가로 길이
		int height = Integer.parseInt(st.nextToken()); // 세로 길이

		int N = Integer.parseInt(br.readLine()); // 상점의 개수
		int[][] map = new int[N+1][2]; // 상점의 방향과 상점의 거리

		// 상점 개수+1만큼 반복하며 2차원 배열 초기화
		for (int r = 0; r < N+1; r++) {
			st = new StringTokenizer(br.readLine());
			for (int c = 0; c < 2; c++) {
				map[r][c] = Integer.parseInt(st.nextToken());
			}
		}

		int sum = 0; // 최단거리 합
		int x = map[N][0]; // 동근이의 방향 초기화
		int xD = map[N][1]; // 동근이 위치 거리 초기화

		// 상점 개수만큼 반복하며 최단거리 구하기
		for (int r = 0; r < N; r++) {
			int des = map[r][0]; // 목적지 방향 초기화
			int desD = map[r][1]; // 목적지 위치 거리 초기화

			if (x == des) { // 동근이 방향과 목적지 방향이 같다면
				sum += Math.abs(xD - desD); // 두 거리의 절댓값 구해서 더하기
			} else { // 같지 않다면
				if (x == 1 && des == 2 || x == 2 && des == 1) {
					if (xD + desD > width - xD + width - desD) {
						sum += (width - xD + width - desD + height);
					} else {
						sum += (xD + desD + height);
					}
				} else if (x == 1 && des == 3 || x == 3 && des == 1) {
					sum += (xD + desD);
				} else if (x == 3 && des == 4 || x == 4 && des == 3) {
					if (xD + desD > height - xD + height - desD) {
						sum += (height - xD + height - desD + width);
					} else {
						sum += (xD + desD + width);
					}
				} else if (x == 1 && des == 4) {
					sum += ((width - xD) + desD);
				} else if (x == 2 && des == 3) {
					sum += (xD + (height - desD));
				} else if (x == 2 && des == 4) {
					sum += ((width - xD) + (height - desD));
				} else if (x == 3 && des == 2) {
					sum += ((height - xD) + desD);
				} else if (x == 4 && des == 1) {
					sum += ((width - desD) + xD);
				} else if (x == 4 && des == 2) {
					sum += ((width - desD) + (height - xD));
				}
			}
		}
		System.out.println(sum);
	}
}
