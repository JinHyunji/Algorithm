#include <iostream>
#include <deque>
using namespace std;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	deque<int> dq;
	for (int i = 1; i <= N; i++)
		dq.push_back(i);

	int answer = 0;
	for (int i = 0; i < M; i++)
	{
		int x;
		cin >> x;

		if (dq.front() == x)
		{
			dq.pop_front();
		}
		else
		{
			int pos = -1;
			for (int i = 0; i < dq.size(); i++)
			{
				if (dq[i] == x)
				{
					pos = i;
					break;
				}
			}

			int end = dq.size() - 1;
			if (pos > end - pos)
			{
				// 3번 실행
				while (dq.front() != x)
				{
					int back = dq.back(); dq.pop_back();
					dq.push_front(back);
					answer++;
				}
			}
			else
			{
				// 2번 실행
				while (dq.front() != x)
				{
					int front = dq.front(); dq.pop_front();
					dq.push_back(front);
					answer++;
				}
			}

			dq.pop_front();
		}
	}

	cout << answer;
}