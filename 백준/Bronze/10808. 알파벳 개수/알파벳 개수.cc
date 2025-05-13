#include <iostream>
#include <string>
using namespace std;

int main()
{
	int alphabet[26] = { 0, };
	
	string input;
	cin >> input;

	for (char& ch : input)
	{
		alphabet[ch - 97]++;
	}

	for (int& a : alphabet)
		cout << a << " ";
}