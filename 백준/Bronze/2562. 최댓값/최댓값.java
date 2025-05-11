import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
    	Scanner sc = new Scanner(System.in);
    	int[] arr = new int[10];
    	int index = 0;
    	int max = 0;
    	for(int i=1; i < 10; i++) {
    		arr[i] = sc.nextInt();
    		if(arr[i] > max) {
    			max = arr[i];
    			index = i;
    		}
    	}
    	System.out.println(max);
    	System.out.println(index);
    }
}
