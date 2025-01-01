using System;

class Program
{
    static void Main(string[] args)
    {
        // 1. 문자열 입력 받아 문자 배열에 넣기기
        char[] input = Console.ReadLine().ToCharArray();

        // 2. 총 알파벳 개수 크기의 int 배열 생성 후 -1로 초기화
        int[] alphabets = new int[26];
        for (int i = 0; i < alphabets.Length; i++) 
        {
            alphabets[i] = -1;
        }

        // 3. 문자열 크기만큼 반복문 실행
        for (int i =0; i < input.Length; i++)
        {
            if (alphabets[input[i] - 97] != -1) continue;
            else alphabets[input[i] - 97] = i;    
        }

        // 4. 정답 출력
        foreach (int alpha in alphabets) {
            Console.Write(alpha + " ");
        }
    }
}
