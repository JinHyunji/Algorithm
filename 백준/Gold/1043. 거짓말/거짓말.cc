#include <iostream>
#include <vector>

using namespace std;

int parent[51];  // 부모 노드 정보
bool truth[51];  // 진실을 아는 사람인지 여부

// Union-Find: find 연산 (경로 압축)
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

// Union-Find: union 연산 (집합 합치기)
void union_sets(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) parent[b] = a;
}

int main() {
    int N, M, T;
    cin >> N >> M >> T;

    vector<vector<int>> parties(M);  // 각 파티에 속한 사람 목록
    for (int i = 1; i <= N; i++) parent[i] = i;  // 부모 배열 초기화

    vector<int> truthPeople;
    for (int i = 0; i < T; i++) {
        int p;
        cin >> p;
        truth[p] = true;  // 진실을 아는 사람 표시
        truthPeople.push_back(p);
    }

    for (int i = 0; i < M; i++) {
        int count, first;
        cin >> count;
        if (count > 0) {
            cin >> first;
            parties[i].push_back(first);
        }
        for (int j = 1; j < count; j++) {
            int person;
            cin >> person;
            parties[i].push_back(person);
            union_sets(first, person);  // 같은 파티에 속한 사람들을 한 그룹으로 합침
        }
    }

    // 진실을 아는 사람들의 루트 노드를 찾고, 같은 집합에 속한 사람들도 진실을 알아야 함
    for (int p : truthPeople) {
        truth[find(p)] = true;
    }

    // 각 파티의 대표 노드(루트)가 진실을 알고 있는지 체크
    int lieCount = 0;
    for (const auto& party : parties) {
        if (party.empty()) continue;
        int leader = find(party[0]);
        if (!truth[leader]) lieCount++;  // 거짓말 가능하면 카운트 증가
    }

    cout << lieCount << endl;
    return 0;
}