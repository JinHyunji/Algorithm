import java.util.Scanner;
import java.util.Stack;

public class Main {
    static int[] checkArr = new int[4];
    static int[] myArr = new int[4];
    static int checkSecret = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int S = sc.nextInt();
        int P = sc.nextInt();
        char[] A = sc.next().toCharArray();
        for (int i = 0; i < 4; i++) {
            checkArr[i] = sc.nextInt();
            if(checkArr[i] == 0) checkSecret++;
        }
        int result = 0;

        for (int i = 0; i < P; i++) {
            add(A[i]);
        }

        if(checkSecret == 4) result++;

        for (int i = P; i < S; i++) {
            int j = i - P;
            add(A[i]);
            remove(A[j]);
            if(checkSecret == 4) result++;
        }

        System.out.println(result);
    }

    private static void remove(char c) {
        switch (c) {
            case 'A':
                if(myArr[0] == checkArr[0]) checkSecret--;
                myArr[0]--;
                break;
            case 'C':
                if(myArr[1] == checkArr[1]) checkSecret--;
                myArr[1]--;
                break;
            case 'G':
                if(myArr[2] == checkArr[2]) checkSecret--;
                myArr[2]--;
                break;
            case 'T':
                if(myArr[3] == checkArr[3]) checkSecret--;
                myArr[3]--;
                break;
        }
    }

    private static void add(char c) {
        switch (c) {
            case 'A':
                myArr[0]++;
                if(myArr[0] == checkArr[0]) checkSecret++;
                break;
            case 'C':
                myArr[1]++;
                if(myArr[1] == checkArr[1]) checkSecret++;
                break;
            case 'G':
                myArr[2]++;
                if(myArr[2] == checkArr[2]) checkSecret++;
                break;
            case 'T':
                myArr[3]++;
                if(myArr[3] == checkArr[3]) checkSecret++;
                break;
        }
    }
}