import java.util.Arrays;
import java.util.Scanner;


public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int[] a = new int[N];
        for (int i = 0; i < N; i++) {
            a[i] = sc.nextInt();
        }

        int i = 0;
        int j = N-1;
        int count = 0;

        Arrays.sort(a);

        while (i < j) {
            if (a[i] + a[j] == M) {
                ++i;
                --j;
                ++count;
            } else if (a[i] + a[j] < M) {
                ++i;
            } else {
                --j;
            }
        }

        System.out.println(count);
    }
}