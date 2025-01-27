#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> result;

void Combi(int start);

int main()
{
	cin >> N >> M;

	Combi(1);
}

void Combi(int start)
{
	if (result.size() == M)
	{
		for (int i : result)
		{
			cout << i << " ";
		}
		cout << endl;
		return;
	}


	for (int i = start; i <= N; i++)
	{
		result.push_back(i);
		Combi(i + 1);
		result.pop_back();
	}
}