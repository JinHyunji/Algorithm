import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


class Node {
	Node next;
	Node pre;
	String data;
	
	Node() {}
	Node(String data) {
		this.data = data;
	}
}

class DoublyLinkedList {
	Node head;
	Node tail;
	int size;
	
	DoublyLinkedList() {
		head = new Node();
		tail = new Node();
		head.next = tail;
		tail.pre = head;
	}
	
	// 삽입
	// 맨 뒤에 삽입
	void add(String data) {
		Node newNode = new Node(data);
		
		newNode.next = tail;
		newNode.pre = tail.pre;
		
		tail.pre.next = newNode;
		tail.pre = newNode;
		
		size++;
	}
	
	// 중간에 삽입
	void add(int idx, String data) {
		if (idx < 0 || idx > size) {
			System.out.println("인덱스 범위를 벗어났습니다.");
			return;
		}
		
		Node newNode = new Node(data);
		Node curr = head;
		
		for (int i = 0; i < idx; i++) {
			curr = curr.next;
		}
		
		newNode.next = curr.next;
		newNode.pre = curr;
		
		newNode.next.pre = newNode;
		newNode.pre.next = newNode;
		
		size++;
	}
	
	// 삭제
	void remove(int idx) {
		if (idx < 0 || idx >= size) {
			System.out.println("삭제할 노드가 없습니다.");
			return;
		}
		
		Node rmNode = head;
		for (int i = 0; i <= idx; i++) {
			rmNode = rmNode.next;
		}
		
		rmNode.next.pre = rmNode.pre;
		rmNode.pre.next = rmNode.next;
		
		size--;
	}
	
	// 조회
	void printList() {
		Node curr = head.next;
		
		for (int i = 0; i < 10; i++) {
			System.out.print(curr.data + " ");
			curr = curr.next;
		}
		
		System.out.println();
	}
	
}

public class Solution {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		DoublyLinkedList list;

		for (int t = 1; t <= 10; t++) {
			list = new DoublyLinkedList();
			
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
