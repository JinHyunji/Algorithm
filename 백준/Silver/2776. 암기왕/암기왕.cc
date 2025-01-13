#include <iostream>
#include <set>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int T;
	std::cin >> T;

	for (int t = 0; t < T; t++)
	{
		int N, M;
		std::cin >> N;

		std::set<int> note;

		for (int i = 0; i < N; i++)
		{
			int num;
			std::cin >> num;
			note.insert(num);
		}

		std::cin >> M;
		std::string output;

		for (int i = 0; i < M; i++)
		{
			int num;
			std::cin >> num;
			
			if (note.find(num) != note.end())
			{
				output += "1\n";
			}
			else
			{
				output += "0\n";
			}
		}

		std::cout << output;
	}
}