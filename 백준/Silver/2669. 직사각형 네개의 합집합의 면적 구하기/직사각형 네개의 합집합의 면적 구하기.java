import java.util.ArrayList;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[][] square = new int[101][101];
		
		for (int i = 0; i < 4; i++) {
			int x1 = sc.nextInt();
			int y1 = sc.nextInt();
			int x2 = sc.nextInt();
			int y2 = sc.nextInt();
			for(int y = y1; y < y2; y++) {
				for(int x = x1; x < x2; x++) {
					square[y][x] = 1;
				}
			}
		}
		
		int answer = 0;
		
		for(int y = 1; y < 101; y++) {
			for(int x = 1; x < 101; x++) {
				answer += square[y][x];
			}
		}
		
		System.out.println(answer);
	}

}
