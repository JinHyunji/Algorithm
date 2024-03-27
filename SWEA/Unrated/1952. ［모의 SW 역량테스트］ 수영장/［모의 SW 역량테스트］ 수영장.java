import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Solution {

	static int[] months = new int[13]; // 인덱스 1부터 사용(1월~12월)
	static int[] prices = new int[4];
	static int ans;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int T = Integer.parseInt(br.readLine());
		
		for (int t = 1; t <= T; t++) {
			
			// 요금 저장
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < 4; i++) {
				prices[i] = Integer.parseInt(st.nextToken());
			}
			
			// 이용 계획 저장 (1부터 12까지)
			st = new StringTokenizer(br.readLine());
			for (int i = 1; i < 13; i++) {
				months[i] = Integer.parseInt(st.nextToken());
			}
			
			ans = prices[3]; // 1년권 금액으로 초기화
			
			DFS(0, 1); // 0원, 1월부터 탐색 시작 
			
			System.out.println("#" + t + " " + ans);
		}
	}

	private static void DFS(int price, int month) {
		if (price >= ans) {
			return;
		}
		
		if (month > 12) {
			if (price < ans)
				ans = price;
			return;
		}
		
		// 1일권 구매시
		DFS(price+prices[0]*months[month], month+1);
		
		// 1달권 구매시
		DFS(price+prices[1], month+1);
		
		// 3달권 구매시
		DFS(price+prices[2], month+3);
	}
}
