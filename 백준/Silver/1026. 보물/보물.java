import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        
        int N = Integer.parseInt(br.readLine());
        int S = 0;
        int[] A = new int[N];
        int[] B = new int[N];
        
        for (int j = 0; j < 2; j++) {
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < N; i++) {
                if (j == 0)
                    A[i] = Integer.parseInt(st.nextToken());
                if (j == 1)
                    B[i] = Integer.parseInt(st.nextToken());
            }
        }
        
        Arrays.sort(A);
        Arrays.sort(B);
        
        for (int i = 0; i < N; i++) {
            S += A[i] * B[N-1-i];
        }
        System.out.println(S);
    }
}