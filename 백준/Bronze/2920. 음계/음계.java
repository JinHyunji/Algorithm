
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        // 변수 선언
        int asc = 1;
        int desc = 8;
        String answer = "mixed";

        // 연주 타입 체크
        for (int i = 1; i < 9; i++) {
            int num = Integer.parseInt(st.nextToken());

            if (num == asc) {
                answer = "ascending";
                ++asc;
                desc = 0;
                continue;
            } else if (num == desc) {
                answer = "descending";
                --desc;
                asc = 0;
                continue;
            } else {
                answer = "mixed";
                break;
            }
        }

        System.out.println(answer);
    }
}