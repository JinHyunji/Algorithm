#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    std::vector<int> dots(N);
    for (int i = 0; i < N; i++) {
        std::cin >> dots[i];
    }

    // 정렬
    std::sort(dots.begin(), dots.end());

    std::string output;
    for (int i = 0; i < M; i++) {
        int start, end;
        std::cin >> start >> end;

        // lower_bound와 upper_bound 사용
        int startIdx = std::lower_bound(dots.begin(), dots.end(), start) - dots.begin();
        int endIdx = std::upper_bound(dots.begin(), dots.end(), end) - dots.begin() - 1;

        // 범위 내 원소 개수 계산
        if (startIdx > endIdx) {
            output += "0\n";
        }
        else {
            output += std::to_string(endIdx - startIdx + 1) + "\n";
        }
    }

    std::cout << output;

    return 0;
}