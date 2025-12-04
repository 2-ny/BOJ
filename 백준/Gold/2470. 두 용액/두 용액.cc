#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solution(int n, vector<int>& solutions) {
	sort(solutions.begin(), solutions.end());	// 오름차순 정렬

	if(solutions[0] >= 0) {
		// 모든 용액이 0 또는 양수일 경우 0번째, 1번째 용액을 혼합
		cout << solutions[0] << " " << solutions[1] << "\n";
		return;
	}
	else if(solutions[n - 1] <= 0) {
		// 모든 용액이 음수 또는 0일 경우 n - 2번째, n - 1번째 용액을 혼합
		cout << solutions[n - 2] << " " << solutions[n - 1] << "\n";
		return;
	}

	// 양수, 음수 용액이 모두 존재하는 경우
	int left = 0, right = n - 1;
	int sum = solutions[left] + solutions[right];
	int min_value = abs(sum);
	int min_left = 0, min_right = n - 1;

	while(left < right) {
		if(sum > 0) {
			right--;
		}
		else if(sum < 0) {
			left++;
		}

		if(left == right) {
			break;
		}

		sum = solutions[left] + solutions[right];

		if(sum == 0) {
			// sum == 0 -> 종료
			cout << solutions[left] << " " << solutions[right] << "\n";
			return;
		}

		if(abs(sum) < min_value) {
			min_left = left;
			min_right = right;

			min_value = abs(sum);
		}
	}

	cout << solutions[min_left] << " " << solutions[min_right] << "\n";
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