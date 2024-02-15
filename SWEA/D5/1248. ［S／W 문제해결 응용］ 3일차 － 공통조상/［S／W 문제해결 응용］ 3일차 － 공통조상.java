
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Node {
	int num;
	Node left;
	Node right;
	Node up;

	Node() {
	}

	Node(int num) {
		this.num = num;
	}
}

public class Solution {

	static int cnt;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			cnt = 0;
			st = new StringTokenizer(br.readLine());
			int V = Integer.parseInt(st.nextToken());
			int E = Integer.parseInt(st.nextToken());
			int V1 = Integer.parseInt(st.nextToken());
			int V2 = Integer.parseInt(st.nextToken());

			Node[] nodes = new Node[V + 1];

			for (int i = 1; i <= V; i++) {
				nodes[i] = new Node();
				nodes[i].num = i;
			}

			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < E; i++) {
				int parent = Integer.parseInt(st.nextToken());
				int child = Integer.parseInt(st.nextToken());

				if (nodes[parent].left == null) {
					nodes[parent].left = nodes[child];
				} else {
					nodes[parent].right = nodes[child];
				}

				nodes[child].up = nodes[parent];
			}

			// 부모 찾기
			Queue<Node> q = new LinkedList<>();
			Queue<Node> q2 = new LinkedList<>();

			Node v1 = nodes[V1].up;
			while (v1.num != 1) {
				q.offer(v1);
				v1 = v1.up;
			}
			q.offer(v1);
			
			Node v2 = nodes[V2].up;
			while (v2.num != 1) {
				q2.offer(v2);
				v2 = v2.up;
			}
			q2.offer(v2);
			
			while (q.size() != q2.size()) {
				if (q.size() > q2.size())
					q.poll();
				else
					q2.poll();
			}
			
		
			while (q.peek() != q2.peek()) {
				q.poll();
				q2.poll();
			}
			
			Node coParent = q.poll();
			
			// 서브 트리 크기 구하기
			preorder(coParent);

			System.out.println("#" + t + " " + coParent.num + " " + cnt);
		}
	}

	// VLR
	static void preorder(Node node) {
		if (node == null)
			return;
		cnt++;
		preorder(node.left);
		preorder(node.right);

	}
}
