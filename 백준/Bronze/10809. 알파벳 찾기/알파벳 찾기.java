
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        // 1. 문자열 입력 받기
        String input = br.readLine();

        // 2. 총 알파벳 수 크기의 int 배열 생성 및 -1 초기화
        int[] alphabets = new int[26];
        for (int i = 0; i < alphabets.length; i++)
        {
            alphabets[i] = -1;
        }

        // 3. 문자열 크기만큼 반복문 실행
        for (int i = 0; i < input.length(); i++)
        {
            char c = input.charAt(i);
            if (alphabets[c-97] != -1) continue;
            else alphabets[c-97] = i;
        }

        // 4. StringBuilder에 출력값 저장
        for (int alpha : alphabets)
        {
            sb.append(alpha + " ");
        }

        System.out.println(sb);
    }
}