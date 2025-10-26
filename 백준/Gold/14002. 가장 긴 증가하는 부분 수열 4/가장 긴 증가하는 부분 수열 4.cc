#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

void solution(int n, const vector<int>& sequence) {
	// LIS[k]: sequence[k]를 마지막 원소로 하는 증가하는 부분 수열의 길이
	vector<int> LIS(n, 1);

	for(int i = 1; i < n; i++) {
		for(int j = 0; j < i; j++) {
			if(sequence[j] < sequence[i]) {
				LIS[i] = max(LIS[i], LIS[j] + 1);
			}
		}
	}

	int max_length = *max_element(LIS.begin(), LIS.end());
	cout << max_length << "\n";

	stack<int> lis_sequence;
	int current_length = max_length;
	for(int i = n - 1; i >= 0; i--) {
		if(LIS[i] == current_length) {
			lis_sequence.push(sequence[i]);
			current_length--;
		}

		if(current_length == 0) {
			break;
		}
	}

	while(!lis_sequence.empty()) {
		cout << lis_sequence.top() << " ";
		lis_sequence.pop();
	}
	cout << "\n";
}

int main() {
	int n;
	cin >> n;

	vector<int> sequence(n);

	for(int i = 0; i < n; i++) {
		cin >> sequence[i];
	}

	solution(n, sequence);

	return 0;
}