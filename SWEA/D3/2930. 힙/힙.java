
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Solution {

	static int[] heap;
	static int heapSize;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int T = Integer.parseInt(br.readLine());
		ArrayList<Integer> list;
		
		for (int t = 1; t <= T; t++) {
			int N = Integer.parseInt(br.readLine());
			
			heap = new int[N + 1];
			heapSize = 0;
			list = new ArrayList<>();
			
			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				int x = Integer.parseInt(st.nextToken());
				if (x == 1) {
					int data = Integer.parseInt(st.nextToken());
					pushHeap(data);
				} else {
					list.add(popHeap());
				}
			}

			System.out.print("#" + t + " ");
			for (int i = 0; i < list.size(); i++) {
				System.out.print(list.get(i) + " ");
			}
			System.out.println();
		}
	}

	static void pushHeap(int x) {
		heap[++heapSize] = x;

		int ch = heapSize;
		int p = heapSize / 2;

		while (p > 0 && heap[p] < heap[ch]) {
			int tmp = heap[p];
			heap[p] = heap[ch];
			heap[ch] = tmp;

			ch = p;
			p = ch / 2;
		}
	}

	static int popHeap() {
		if (heapSize == 0) {
			return -1;
		}
		
		int root = heap[1];
		heap[1] = heap[heapSize--];

		int p = 1;
		int ch = p * 2;

		if (ch + 1 <= heapSize && heap[ch] < heap[ch + 1]) {
			ch++;
		}
		
		while (ch <= heapSize && heap[p] < heap[ch]) {
			
			int tmp = heap[p];
			heap[p] = heap[ch];
			heap[ch] = tmp;
			
			p = ch;
			ch = p * 2;
			
			if (ch + 1 <= heapSize && heap[ch] < heap[ch + 1]) {
				ch++;
			}
		}

		return root;
	}

}
