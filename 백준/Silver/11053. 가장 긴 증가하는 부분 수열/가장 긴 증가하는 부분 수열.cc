#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution(int n, const vector<int>& sequence) {
	// LIS[j]: sequence[j]으로 끝나는 증가하는 부분 수열의 길이
	vector<int> LIS(n, 1);

	for(int i = 1; i < n; i++) {
		for(int j = 0; j < i; j++) {
			if(sequence[i] > sequence[j]) {
				LIS[i] = max(LIS[i], LIS[j] + 1);
			}
		}
	}

	int max_length = *max_element(LIS.begin(), LIS.end());

	cout << max_length << "\n";
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