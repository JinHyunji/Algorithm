import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static int M, N, H, zeroCount, day;
    static int[][][] arr;
    static int[] dn = {0, 0, -1, 1, 0, 0};
    static int[] dm = {0, 0, 0, 0, -1, 1};
    static int[] dh = {1, -1, 0, 0, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());
        zeroCount = 0;
        day = -1; // 처음에는 0으로 시작하는 게 아니라 -1로 시작합니다. 
        arr = new int[H][N][M];

        Queue<int[]> queue = new LinkedList<>();

        for (int h = 0; h < H; h++) {
            for (int n = 0; n < N; n++) {
                st = new StringTokenizer(br.readLine());
                for (int m = 0; m < M; m++) {
                    arr[h][n][m] = Integer.parseInt(st.nextToken());
                    if (arr[h][n][m] == 0) {
                        zeroCount++;
                    } else if (arr[h][n][m] == 1) {
                        queue.add(new int[]{h, n, m, 0});
                    }
                }
            }
        }

        if (zeroCount == 0) {
            System.out.println(0);
            return;
        }

        while (!queue.isEmpty()) {
            int[] node = queue.poll();

            for (int i = 0; i < 6; i++) {
                int nh = node[0] + dh[i];
                int nn = node[1] + dn[i];
                int nm = node[2] + dm[i];

                if (nh >= 0 && nh < H && nn >= 0 && nn < N && nm >= 0 && nm < M && arr[nh][nn][nm] == 0) {
                    arr[nh][nn][nm] = 1;
                    queue.add(new int[]{nh, nn, nm, node[3] + 1});
                    day = Math.max(day, node[3] + 1); // 여러 토마토가 다른 날에 익을 수 있으므로 최대값을 구합니다.
                    zeroCount--;
                }
            }
        }

        if (zeroCount > 0) {
            System.out.println(-1);
        } else {
            System.out.println(day);
        }
    }
}
