
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());

        for (int t = 0; t < T; t++) {
            st = new StringTokenizer(br.readLine());

            int H = Integer.parseInt(st.nextToken());
            int W = Integer.parseInt(st.nextToken());
            int N = Integer.parseInt(st.nextToken());

            int floor;
            int no;

            if (N % H == 0) {
                floor = H * 100;
                no = N / H;
            } else {
                if (N < H) {
                    floor = N * 100;
                    no = 1;
                } else {
                    floor = N % H * 100;
                    no = N / H + 1;
                }
            }

            sb.append(floor+no).append("\n");
        }

        System.out.println(sb);
    }
}
