import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static int N, min;
	static int[] people;
	static List<ArrayList<Integer>> map;
	static boolean[] selected, visited;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		min = Integer.MAX_VALUE;
		people = new int[N];
		map = new ArrayList<>();
		selected = new boolean[N];
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			people[i] = Integer.parseInt(st.nextToken());
		}
		
		for (int i = 0; i < N; i++) {
			map.add(new ArrayList<>());
		}
		
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			int cnt = Integer.parseInt(st.nextToken());
			for (int j = 0; j < cnt; j++) {
				int num = Integer.parseInt(st.nextToken());
				map.get(i).add(num-1);
			}
		}
		
		divide(0);
		
		if (min == Integer.MAX_VALUE) min = -1;
		
		System.out.println(min);
	}

	private static void divide(int idx) {
		if (idx == N) {
			List<Integer> aList = new ArrayList<>();
			List<Integer> bList = new ArrayList<>();
			
			for (int i = 0; i < N; i++) {
				if (selected[i]) aList.add(i);
				else bList.add(i);
			}
			
			if (aList.size() == 0 || bList.size() == 0) return;
			
			if (check(aList) && check(bList)) 
				getDiff();
			
			return;
		}
		
		selected[idx] = true;
		divide(idx+1);
		selected[idx] = false;
		divide(idx+1);
	}

	private static boolean check(List<Integer> list) {
		Queue<Integer> q = new LinkedList<>();
		visited = new boolean[N];
		visited[list.get(0)] = true;
		q.add(list.get(0));
		
		int count = 1;
		
		while (!q.isEmpty()) {
			int cur = q.poll();	
			
			for (int i = 0; i < map.get(cur).size(); i++) {
				int y = map.get(cur).get(i);
				
				if (list.contains(y) && !visited[y]) {
					q.add(y);
					visited[y] = true;
					count++;
				}
			}
		}
		
		if (count == list.size()) 
			return true;
		else
			return false;
	}

	private static void getDiff() {
		int pA = 0;
		int pB = 0;
		
		for (int i = 0; i < N; i++) {
			if (selected[i])
				pA += people[i];
			else 
				pB += people[i];
		}
		
		min = Math.min(min, Math.abs(pA-pB));
	}
}