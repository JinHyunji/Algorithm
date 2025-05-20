#include <iostream>
#include <string>
using namespace std;

const int MX = 10000;
int dat[2 * MX + 1];
int head = MX, tail = MX;

void push_front(int x) {
	dat[--head] = x;
}

void push_back(int x) {
	dat[tail++] = x;
}

int size()
{
	return tail - head;
}

bool empty()
{
	return size() == 0 ? true : false;
}

void pop_front() {
	head++;
}

void pop_back() {
	tail--;
}

int front() {
	return dat[head];
}

int back() {
	return dat[tail - 1];
}


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;

		if (input == "push_front")
		{
			int x;
			cin >> x;

			push_front(x);
		}
		else if (input == "push_back")
		{
			int x;
			cin >> x;

			push_back(x);
		}
		else if (input == "pop_front")
		{
			if (empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << front() << "\n";
				pop_front();
			}
		}
		else if (input == "pop_back")
		{
			if (empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << back() << "\n";
				pop_back();
			}
		}
		else if (input == "size")
		{
			cout << size() << "\n";
		}
		else if (input == "empty")
		{
			cout << empty() << "\n";
		}
		else if (input == "front")
		{
			if (empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << front() << "\n";
			}
		}
		else
		{
			if (empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << back() << "\n";
			}
		}
	}
}