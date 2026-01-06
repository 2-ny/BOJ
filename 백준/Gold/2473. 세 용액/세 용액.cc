#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const long long INF = 4e18;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<long long> solutions(n);

	for(int i = 0; i < n; i++) {
		cin >> solutions[i];
	}

	sort(solutions.begin(), solutions.end());

	vector<int> answer(3);
	long long min_sum = INF;

	for(int i = 0; i < n - 2; i++) {
		int left = i + 1;
		int right = n - 1;

		while(left < right) {
			long long current_sum = solutions[i] + solutions[left] + solutions[right];

			if(llabs(current_sum) < min_sum) {
				min_sum = llabs(current_sum);

				answer[0] = i;
				answer[1] = left;
				answer[2] = right;
			}

			if(current_sum == 0) {
				break;
			}

			if(current_sum > 0) {
				right--;
			}
			else {
				left++;
			}
		}
	}

	for(auto index : answer) {
		cout << solutions[index] << " ";
	}

	cout << "\n";

	return 0;
}