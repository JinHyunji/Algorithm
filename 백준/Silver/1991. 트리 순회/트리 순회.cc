#include <iostream>
#include <vector>
using namespace std;

int N;
pair<char, char> node[26];

void preorder(char curr)
{
	if (curr == '.') return;
	cout << curr;
	preorder(node[curr - 'A'].first);
	preorder(node[curr - 'A'].second);
}

void inorder(char curr)
{
	if (curr == '.') return;
	inorder(node[curr - 'A'].first);
	cout << curr;
	inorder(node[curr - 'A'].second);
}

void postorder(char curr)
{
	if (curr == '.') return;
	postorder(node[curr - 'A'].first);
	postorder(node[curr - 'A'].second);
	cout << curr;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		char parent, left, right;
		cin >> parent >> left >> right;
		node[parent - 'A'] = make_pair(left, right);
	}

	preorder('A');

	cout << endl;
	inorder('A');

	cout << endl;
	postorder('A');

	return 0;
}