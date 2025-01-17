#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int N, n;
	cin >> N;

	vector<int> liquid(N);
	for (int i = 0; i < N; i++) {
		cin >> n;
		liquid[i] = n;
	}

	sort(liquid.begin(), liquid.end());

	int start = 0;
	int end = N - 1;
	int result[]{ 0,0 };
	int absMin = 2000000000;

	while (start < end) {
		int sum = liquid[start] + liquid[end];
		int absSum = abs(sum);

		if (sum < 0) {
			if (absSum < absMin) {
				result[0] = liquid[start];
				result[1] = liquid[end];
				absMin = absSum;
			}
			start += 1;
		}
		else if (sum > 0) {
			if (absSum < absMin) {
				result[0] = liquid[start];
				result[1] = liquid[end];
				absMin = absSum;
			}
			end -= 1;
		}
		else {
			result[0] = liquid[start];
			result[1] = liquid[end];
			break;
		}
	}

	if (result[0] < result[1]) {
		cout << result[0] << " " << result[1];
	}
	else {
		cout << result[1] << " " << result[2];
	}
}