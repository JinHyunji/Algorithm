import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int N, M, year;
    static int[][] map;
    static boolean[][] visited;
    static int[] dr = { -1, 1, 0, 0 };
    static int[] dc = { 0, 0, -1, 1 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        year = 0;
        map = new int[N][M];

        for (int n = 0; n < N; n++) {
            st = new StringTokenizer(br.readLine());
            for (int m = 0; m < M; m++) {
                map[n][m] = Integer.parseInt(st.nextToken());
            }
        }

        while (true) {
            // 시간의 경과 체크
            ++year;

            // 빙산 녹이기
            int[][] tempMap = new int[N][M];
            for (int n = 0; n < N; n++) {
                for (int m = 0; m < M; m++) {
                    tempMap[n][m] = map[n][m];
                }
            }

            for (int n = 1; n < N - 1; n++) {
                for (int m = 1; m < M - 1; m++) {
                    if (map[n][m] != 0) {
                        int seaCount = 0;
                        for (int i = 0; i < 4; i++) {
                            int nr = n + dr[i];
                            int nc = m + dc[i];

                            if (map[nr][nc] == 0) {
                                seaCount++;
                            }
                        }
                        tempMap[n][m] = Math.max(0, map[n][m] - seaCount);
                    }
                }
            }

            map = tempMap;

            // 모두 녹았는지 체크
            if (isAllMelted()) {
                year = 0;
                break;
            }

            // 빙산이 나뉘었는지 체크
            visited = new boolean[N][M];
            boolean foundIceberg = false;
            boolean separated = false;

            for (int n = 1; n < N - 1; n++) {
                for (int m = 1; m < M - 1; m++) {
                    if (map[n][m] != 0 && !visited[n][m]) {
                        if (foundIceberg) {
                            separated = true;
                            break;
                        }
                        check(n, m);
                        foundIceberg = true;
                    }
                }
                if (separated) {
                    break;
                }
            }

            if (separated) {
                break;
            }
        }

        System.out.println(year);
    }

    private static void check(int r, int c) {
        visited[r][c] = true;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < N && nc >= 0 && nc < M && map[nr][nc] != 0 && !visited[nr][nc]) {
                check(nr, nc);
            }
        }
    }

    private static boolean isAllMelted() {
        for (int n = 1; n < N - 1; n++) {
            for (int m = 1; m < M - 1; m++) {
                if (map[n][m] != 0) {
                    return false;
                }
            }
        }
        return true;
    }
}
