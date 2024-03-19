class Solution {
    public int solution(String[] friends, String[] gifts) {
        int[][] rec = new int[friends.length][friends.length];
        int[][] count = new int[friends.length][4];
        
        // 준 사람, 받은 사람 계산
        for (int i = 0; i < gifts.length; i++) {
            String[] tmp = gifts[i].split(" ");
            
            int g = -1;
            int r = -1;
            
            // 준 선물, 받은 선물 계산
            for (int j = 0; j < friends.length; j++) {
                if (tmp[0].equals(friends[j])) {
                    count[j][0]++;
                    g = j;
                }
                if (tmp[1].equals(friends[j])) {
                    count[j][1]++;
                    r = j;
                }
            }
            rec[g][r]++;
        }
        // 선물 지수 계산
        for (int j = 0; j < friends.length; j++) {
            count[j][2] = count[j][0] - count[j][1]; 
        }
        
        // 다음달 가장 많은 선물 수 계산
        for (int i = 0; i < friends.length; i++) {
            for (int j = 0; j < friends.length; j++) {
                if (rec[i][j] > rec[j][i]) {
                    count[i][3]++;
                } else if (rec[i][j] < rec[j][i]) {
                    count[j][3]++;
                } else {
                    if (count[i][2] > count[j][2]) {
                        count[i][3]++;
                    } else if (count[i][2] < count[j][2]) {
                        count[j][3]++;
                    } 
                }
            }
        }
        
        int max = 0;
        
        for (int i = 0; i < count.length; i++) {
            if (count[i][3] > max) max = count[i][3];
        }

        return max / 2;
    }
}