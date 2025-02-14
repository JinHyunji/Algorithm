#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, roomCnt = 1; // 회의실 개수는 1개 이상
vector<pair<int, int>> mTimes;
priority_queue<int, vector<int>, greater<int>> pq; // 최소힙

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		mTimes.push_back(make_pair(a, b));
	}

	// 오름차순 정렬 : 시작 시간 
	sort(mTimes.begin(), mTimes.end());

	// 첫 번째 회의 큐에 넣기
	pq.push(mTimes[0].second);

	for (int i = 1; i < N; i++)
	{
		if (mTimes[i].first >= pq.top()) // 들어갈 회의실이 있으면
		{
			pq.pop();
			pq.push(mTimes[i].second); // 기존 회의실 회의 끝나는 시간 갱신
		}
		else // 들어갈 회의실이 없으면
		{
			roomCnt++; // 회의실 개수 추가
			pq.push(mTimes[i].second); // 새로운 회의실 회의 끝나는 시간 추가
		}
	}

	cout << roomCnt;
}