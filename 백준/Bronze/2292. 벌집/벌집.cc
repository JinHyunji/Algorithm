#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int layer = 1; // 최소 이동 횟수 (1번 방 포함)
    int max_num = 1; // 해당 layer의 마지막 번호 (1, 7, 19, 37, ...)

    while (N > max_num) {
        max_num += 6 * layer; // 각 층마다 6의 배수만큼 증가
        layer++;
    }

    cout << layer << endl;
    return 0;
}