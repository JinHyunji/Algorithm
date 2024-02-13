
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Node {
	String data;
	Node link;

	Node() {
	}

	Node(String data) {
		this.data = data;
	}
}

class LinkedList {
	Node head;
	int size;

	LinkedList() {
		head = new Node();
	}

//	// 앞에서부터 삽입
//	void add(String data) {
//		Node newNode = new Node(data);
//		
//		newNode.link = head.link;
//		head.link = newNode;
//		
//		size++;
//	}

	// 중간 삽입
	void add(int idx, String data) {
		if (idx < 0 || idx > size) {
			System.out.println("인덱스 범위를 초과했습니다.");
			return;
		}

		Node newNode = new Node(data);
		Node curr = head;

		for (int i = 0; i < idx; i++) {
			curr = curr.link;
		}

		newNode.link = curr.link;
		curr.link = newNode;

		size++;
	}

	// 뒤에 삽입
	void add(String data) {
		Node newNode = new Node(data);

		Node curr = head;
		while (curr.link != null) {
			curr = curr.link;
		}

		curr.link = newNode;

		size++;
	}

	// 삭제
	void remove(int idx) {
		if (idx < 0 || idx >= size) {
			System.out.println("삭제할 노드가 없습니다.");
			return;
		}
		
		Node curr = head;
		for (int i = 0; i < idx; i++) {
			curr = curr.link;
		}
		
		curr.link = curr.link.link;
		
		size--;
	}

	// 조회
	void printList() {
		Node curr = head.link;
		for (int i = 0; i < 10; i++) {
			System.out.print(curr.data + " ");
			curr = curr.link;
		}
		System.out.println();
	}
}

public class Solution {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		LinkedList list;

		for (int t = 1; t <= 10; t++) {
			list = new LinkedList();
			
			int N = Integer.parseInt(br.readLine());
			
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < N; i++) {
				list.add(st.nextToken());
			}
			
			int M = Integer.parseInt(br.readLine());
			
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < M; i++) {
				String cmd = st.nextToken();
				
				switch (cmd) {
				case "I":
					int idx = Integer.parseInt(st.nextToken());
					int K = Integer.parseInt(st.nextToken());
					for (int j = 0; j < K; j++) {
						list.add(idx + j, st.nextToken());
					}
					break;
				case "D":
					int x = Integer.parseInt(st.nextToken());
					int y = Integer.parseInt(st.nextToken());
					for (int j = 0; j < y; j++) {
						list.remove(x);
					}
					break;
				case "A":
					int z = Integer.parseInt(st.nextToken());
					for (int j = 0; j < z; j++) {
						list.add(st.nextToken());
					}
					break;
				}
			}
			
			System.out.print("#" + t + " ");
			list.printList();
			
		}
	}
}
