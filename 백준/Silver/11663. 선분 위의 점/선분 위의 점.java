
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {

    static int[] dots;
    static int N, M;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();


        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        dots = new int[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            dots[i] = Integer.parseInt(st.nextToken());
        }

        // 오름차순 정렬
        Arrays.sort(dots);

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());

            int startIdx = findIdx(start, 0);
            int endIdx = findIdx(end, 1);

            sb.append(endIdx - startIdx + 1).append("\n");
        }

        System.out.println(sb);
    }

    public static int findIdx(int pos, int type) {
        int min = 0;
        int max = dots.length - 1;
        int result = -1;

        if (type == 0) {
            while (min <= max) {
                int mid = (min + max) / 2;

                if (dots[mid] > pos) {
                    max = mid - 1;
                    result = mid;
                }
                else if (dots[mid] < pos) {
                    min = mid + 1;
                    result = min;
                }
                else {
                    return mid;
                }
            }
        } else {
            while (min <= max) {
                int mid = (min + max) / 2;

                if (dots[mid] > pos) {
                    max = mid - 1;
                    result = max;
                }
                else if (dots[mid] < pos) {
                    min = mid + 1;
                    result = mid;
                }
                else {
                    return mid;
                }
            }
        }

        return result;
    }
}