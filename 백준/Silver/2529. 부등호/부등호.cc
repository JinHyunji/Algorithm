#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int K;
vector<char> signs;
vector<bool> visited(10);
string minNum = "9999999999"; // 충분히 큰 값으로 초기화
string maxNum = "0000000000"; // 충분히 작은 값으로 초기화

// 백트래킹 함수
void backtrack(int depth, string num) {
    if (depth == K + 1) { // K+1개의 숫자를 선택한 경우
        if (num < minNum) minNum = num;
        if (num > maxNum) maxNum = num;
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (!visited[i]) {
            if (depth == 0 || (signs[depth - 1] == '<' && num.back() < '0' + i) || (signs[depth - 1] == '>' && num.back() > '0' + i)) {
                visited[i] = true;
                backtrack(depth + 1, num + (char)('0' + i));
                visited[i] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> K;
    signs.resize(K);
    for (int i = 0; i < K; i++) cin >> signs[i];

    // 백트래킹 실행
    backtrack(0, "");

    // 결과 출력
    cout << maxNum << "\n" << minNum << "\n";
}