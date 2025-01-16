import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int[] lectures = new int[N];
        int start = 0; // 최소 블루레이 크기
        int end = 0; // 최대 블루레이 크기

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            lectures[i] = Integer.parseInt(st.nextToken());

            start = Math.max(start, lectures[i]); // 최소 크기는 가장 큰 강의 길이
            end += lectures[i]; // 최대 크기는 모든 강의 길이의 합
        }

        int result = end; // 결과값 저장 (최소 블루레이 크기)

        while (start <= end) {
            int mid = (start + end) / 2; // 블루레이 크기의 중간값
            int sum = 0;
            int cnt = 1; // 블루레이 개수 (최소 1개)

            for (int i = 0; i < N; i++) {
                if (sum + lectures[i] > mid) {
                    cnt++;
                    sum = lectures[i];
                } else {
                    sum += lectures[i];
                }
            }

            if (cnt <= M) { // 블루레이 개수가 적거나 같으면 크기 줄이기
                result = mid;
                end = mid - 1;
            } else { // 블루레이 개수가 많으면 크기 늘리기
                start = mid + 1;
            }
        }

        System.out.println(result); // 최소 블루레이 크기 출력
    }
}