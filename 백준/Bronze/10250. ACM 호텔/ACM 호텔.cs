using System;

class Program
{
    static void Main(string[] args)
    {
        int T = int.Parse(Console.ReadLine());

        for (int t = 0; t < T; t++)
        {
            string[] nums = Console.ReadLine().Split(" ");

            int H = int.Parse(nums[0]);
            int N = int.Parse(nums[2]);

            int floor = N % H == 0 ? H : N % H;
            int no = N % H == 0 ? N / H : N / H + 1;

            floor *= 100;

            Console.WriteLine(floor + no);
        }
    }
}
