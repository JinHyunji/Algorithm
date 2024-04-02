import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(); int M = sc.nextInt(); int K = sc.nextInt();
		int result = M / N * K;
		System.out.println(result);
	}
}