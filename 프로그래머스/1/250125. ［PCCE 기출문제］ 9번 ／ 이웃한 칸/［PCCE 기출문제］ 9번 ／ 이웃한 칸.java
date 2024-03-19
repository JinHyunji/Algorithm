class Solution {
    public int solution(String[][] board, int h, int w) {
        int n = board.length;
        int count = 0;
        int[] dh = { -1, 1, 0, 0 }; // 상, 하, 좌, 우
        int[] dw = { 0, 0, -1, 1 };
        for (int i = 0; i < 4; i++) {
            int nh = h + dh[i];
            int nw = w + dw[i];
            if (nh >= 0 && nw >= 0 && nh < n && nw < n) {
                if (board[h][w].equals(board[nh][nw])) {
                count++;
                }
            }
            
        }
        return count;
    }
}