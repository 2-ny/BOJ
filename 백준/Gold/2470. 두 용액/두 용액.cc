#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int INF = 2e9;

void solution(int n, vector<int>& solutions) {
	sort(solutions.begin(), solutions.end());	// 오름차순 정렬

	int left = 0, right = n - 1;
	int min_abs = INF;
	int answer_left = 0, answer_right = 0;

	while(left < right) {
		int sum = solutions[left] + solutions[right];

		if(abs(sum) < min_abs) {
			min_abs = abs(sum);
			answer_left = solutions[left];
			answer_right = solutions[right];

			if(sum == 0) {
				break;
			}
		}

		if(sum > 0) {
			right--;
		}
		else if(sum < 0) {
			left++;
		}
	}

	cout << answer_left << " " << answer_right << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> solutions(n);

	for(int i = 0; i < n; i++) {
		cin >> solutions[i];
	}

	solution(n, solutions);

	return 0;
}