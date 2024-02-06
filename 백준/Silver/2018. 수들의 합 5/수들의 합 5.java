import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int sp = 1;
        int ep = 1;
        int sum = 1;
        int count = 1;

        while (ep != n) {
            if (sum < n) {
                sum += ++ep;
            } else if (sum == n) {
                ++count;
                sum += ++ep;
            } else {
                sum -= sp++;
            }
        }

        System.out.println(count);
    }
}