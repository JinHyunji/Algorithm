using System;

class Program
{
    static void Main(string[] args)
    {
        // 입력값 변수에 저장
        int N = int.Parse(Console.ReadLine());

        string[] sizes = Console.ReadLine().Split(" ");

        string[] nums = Console.ReadLine().Split(" ");
        int T = int.Parse(nums[0]);
        int P = int.Parse(nums[1]);

        // 정답 변수
        int tShirtNum = 0;
        int penMaxNum = N / P;
        int penNum = N % P;

        // 사이즈 배열 순회하며 티셔츠 장수와 비교
        for (int i = 0; i < 6; i++)
        {
            int size = int.Parse(sizes[i]);

            if(size == 0) continue;

            // 값이 T보다 작거나 같으면 묶음 +1
            if (size <= T)
            {
                tShirtNum++;
            }
            // 크면 값을 T로 나누기
            else
            {
                // 나머지가 0이면 몫
                if (size % T == 0)
                {
                    tShirtNum += (size / T);
                }
                // 나머지가 0이 아니면 몫 + 1
                else
                {
                    tShirtNum += (size / T) + 1;
                }
            }

        }

        // 출력
        Console.WriteLine(tShirtNum);
        Console.WriteLine(penMaxNum + " " + penNum);
    }
}
