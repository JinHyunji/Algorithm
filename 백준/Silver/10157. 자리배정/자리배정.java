import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int C = Integer.parseInt(st.nextToken()); // 가로
		int R = Integer.parseInt(st.nextToken()); // 세로
		int K = Integer.parseInt(br.readLine()); // 대기 번호

		if (K > C * R) {
			System.out.println(0); // 대기 번호가 좌석보다 많으면 0 출력 후
			return; // 메서드 종료
		}

		int[] dx = { -1, 0, 1, 0 }; // 상 우 하 좌
		int[] dy = { 0, 1, 0, -1 }; // 상 우 하 좌

		boolean[][] visited = new boolean[R][C]; // 방문 확인 여부

		// 초기 x, y값 설정, 대기 번호 확인해줄 변수, 델타배열 인덱스 선언
		int count = 0, x = R - 1, y = 0, dir = 0;

		while (++count != K) { // 대기번호 만날 때까지 반복
			visited[x][y] = true;

			// 새로운 인덱스 생성
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			// 인덱스를 벗어나거나 이미 방문한 곳이면 방향 전환
			if (nx < 0 || ny < 0 || nx >= R || ny >= C || visited[nx][ny]) {
				dir = (++dir % 4);
				nx = x + dx[dir];
				ny = y + dy[dir];
			}

			// 이동한 곳의 인덱스 저장
			x = nx;
			y = ny;
		}

		// 대기번호와 count값이 같아지면 출력
		System.out.println((y + 1) + " " + (R - x));

	}
}
