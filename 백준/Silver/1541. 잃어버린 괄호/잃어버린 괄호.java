import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] arr = br.readLine().split("-");

        int sum = 0;

        for (int i = 0; i < arr.length; i++) {
            String[] temp = arr[i].split("\\+");

            for (String str : temp) {
                if (i == 0) {
                    sum += Integer.parseInt(str);
                } else {
                    sum -= Integer.parseInt(str);
                }
            }
        }

        System.out.println(sum);
    }
}
