#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int L, C;
vector<char> alphabet;
vector<char> selected;
vector<bool> used;

void Code(int idx, int sIdx);

int main()
{
	// 입출력 성능 향상
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 입력
	cin >> L >> C;
	alphabet.resize(C);
	used.resize(C);
	selected.resize(L);

	for (int i = 0; i < C; i++)
	{
		cin >> alphabet[i];
	}
    
    // 오름차순 정렬
	sort(alphabet.begin(), alphabet.end());

	// C개 중 L개 조합
	Code(0, 0);
}

void Code(int idx, int sIdx)
{
	if (sIdx >= L)
	{
		int vowel = 0; // 모음 개수
		int conso = 0; // 자음 개수

		// 조건 확인(자모 개수, 정렬 여부)
		for (char& c : selected)
		{
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') // 모음 개수 체크
			{
				vowel++;
			}
			else // 자음 개수 체크
			{
				conso++;
			}
		}

		if (vowel >= 1 && conso >= 2) // 자모 조건에 부합하면
		{
			// 암호 출력 후 종료
			for (char& c : selected)
			{
				cout << c;
			}
			cout << endl;
			return;
		}
		else // 자모 조건에 부합하지 않으면 종료
			return;
	}

	if (idx >= C) return;

	used[idx] = true;
	selected[sIdx] = alphabet[idx];
	Code(idx + 1, sIdx + 1);
	Code(idx + 1, sIdx);
}
