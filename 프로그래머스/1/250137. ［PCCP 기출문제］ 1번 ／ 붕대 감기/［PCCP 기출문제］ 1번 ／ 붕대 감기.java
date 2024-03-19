class Solution {
    public int solution(int[] bandage, int health, int[][] attacks) {
        int answer = health; // 마지막 체력
        int check = 0; // 연속 성공 체크
        for (int i = 1, j = 0; i <= attacks[attacks.length-1][0]; i++) { // 1초부터 마지막 공격 초까지 증가하며 비교
            if (attacks[j][0] == i) { // 공격 받는 초라면
                answer -= attacks[j][1];
                if (answer <= 0) return -1;
                j++;
                check = 0;
            } else { // 공격받지 않는 초라면
                answer += bandage[1];
                if (answer > health) answer = health;
                check++;
                if (check == bandage[0]) {
                    answer += bandage[2];
                    if (answer > health) answer = health;
                    check = 0;
                }
            }
        }
       
        return answer;
    }
}