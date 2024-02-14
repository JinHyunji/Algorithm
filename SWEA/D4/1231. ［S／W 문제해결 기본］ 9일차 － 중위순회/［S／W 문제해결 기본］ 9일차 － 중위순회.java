import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Node {
	char data;
	Node left;
	Node right;

	Node() {
	}

	Node(char data) {
		this.data = data;
	}
}

public class Solution {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		Node root;
		
		for (int t = 1; t < 11; t++) {
			int N = Integer.parseInt(br.readLine());
			Node[] nodes = new Node[N + 1];

			for (int i = 1; i < N + 1; i++) {
				nodes[i] = new Node();
			}

			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				int num = Integer.parseInt(st.nextToken());
				char data = st.nextToken().charAt(0);
				nodes[num].data = data;
				if (st.hasMoreTokens()) {
					int left = Integer.parseInt(st.nextToken());
					nodes[num].left = nodes[left];
					if (st.hasMoreTokens()) {
						int right = Integer.parseInt(st.nextToken());
						nodes[num].right = nodes[right];
					}
				}
			}
			
			root = nodes[1];
			
			System.out.print("#" + t + " ");
			inorder(root);
			System.out.println();
		}
	}
	
	// LVR
	public static void inorder(Node node) {
		if (node == null) return;
		inorder(node.left);
		System.out.print(node.data);
		inorder(node.right);
	}
}
