import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int width = Integer.parseInt(st.nextToken()); // 가로의 길이
		int height = Integer.parseInt(st.nextToken()); // 세로의 길이

		ArrayList<Integer> widths = new ArrayList<>(); // 입력받은 가로선 담을 리스트
		ArrayList<Integer> heights = new ArrayList<>(); // 입력받은 세로선 담을 리스트

		int N = Integer.parseInt(br.readLine()); // 종이조각 개수
		
		widths.add(0);
		heights.add(0);
		widths.add(width);
		heights.add(height);
		
		for (int i = 0; i < N; i++) { // 조각 개수 만큼 반복
			st = new StringTokenizer(br.readLine());
			int check = Integer.parseInt(st.nextToken()); // 가로 혹은 세로 확인 변수
			int num = Integer.parseInt(st.nextToken()); // 몇 번째 선 자를 건지 담을 변수

			if (check == 0) { // 가로선이라면
				heights.add(num);
			} else { // 세로선이라면
				widths.add(num);
			}
		}

		// 오름차순 정렬
		Collections.sort(widths);
		Collections.sort(heights);


		int[] nwidths = new int[widths.size() - 1]; // 쪼개진 가로 길이 담을 배열
		int[] nheights = new int[heights.size() - 1]; // 쪼개진 세로 길이 담을 배열

		for (int i = 0; i < nwidths.length; i++) {
			nwidths[i] = widths.get(i+1) - widths.get(i);
		}
		for (int i = 0; i < nheights.length; i++) {
			nheights[i] = heights.get(i+1) - heights.get(i);
		}
		
		int max = 0;
		
		for (int r = 0; r < nwidths.length; r++) {
			for (int c = 0; c < nheights.length; c++) {
				if (nwidths[r] * nheights[c] > max) max = nwidths[r] * nheights[c];
			}
		}
		
		System.out.println(max);
	}
}
