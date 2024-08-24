import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main
{
    static int M, n;
    static String str;
    static Set<Integer> set = new HashSet<>();
    static StringBuffer sb = new StringBuffer();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader((System.in)));
        StringTokenizer st;

        M = Integer.parseInt(br.readLine());

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            str = st.nextToken();

            if (str.equals("all")) {
                set.clear();
                for (int j = 1; j <= 20; j++) {
                    set.add(j);
                }
            } else if (str.equals("empty")) {
                set.clear();
            } else {
                n = Integer.parseInt(st.nextToken());

                if (str.equals("add")) {
                    set.add(n);
                } else if (str.equals("remove")) {
                    set.remove(n);
                } else if (str.equals("check")) {
                    if (set.contains(n)) {
                        sb.append(1).append("\n");
                    } else {
                        sb.append(0).append("\n");
                    }
                } else {
                    if (set.contains(n)) {
                        set.remove(n);
                    } else {
                        set.add(n);
                    }
                }
            }
        }

        System.out.println(sb);
    }
}
