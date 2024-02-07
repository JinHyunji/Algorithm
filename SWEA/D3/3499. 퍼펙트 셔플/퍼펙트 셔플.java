import java.io.IOException;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Solution {

	public static void main(String[] args) throws NumberFormatException, IOException {
		Scanner sc = new Scanner(System.in);

		Queue<String> cardA = new LinkedList<>();
		Queue<String> cardB = new LinkedList<>();

		int T = sc.nextInt();

		for (int t = 1; t <= T; t++) {
			int N = sc.nextInt();
			sc.nextLine();

			if (N % 2 == 0) {
				for (int i = 0; i < N / 2; i++) {
					cardA.add(sc.next());
				}
				for (int i = N / 2; i < N; i++) {
					cardB.add(sc.next());
				}
			} else {
				for (int i = 0; i < N / 2 + 1; i++) {
					cardA.add(sc.next());
				}
				for (int i = N / 2 + 1; i < N; i++) {
					cardB.add(sc.next());
				}
			}

			System.out.print("#" + t + " ");
			while (!cardA.isEmpty() || !cardB.isEmpty()) {
				if (!cardA.isEmpty())
					System.out.print(cardA.poll() + " ");
				if (!cardB.isEmpty())
					System.out.print(cardB.poll() + " ");
			}
			System.out.println();
		}
	}

}
