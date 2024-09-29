import java.io.IOException;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
       Scanner sc = new Scanner(System.in);

       int N = Integer.parseInt(sc.nextLine());
       String str = sc.nextLine();
       int sum = 0;

       for (int i = 0; i < str.length(); i++) {
            sum += str.charAt(i) - '0';
       }

        System.out.println(sum);
    }
}