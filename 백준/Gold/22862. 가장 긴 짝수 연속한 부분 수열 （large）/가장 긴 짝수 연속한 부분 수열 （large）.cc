#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution(int n, int k, vector<int>& sequence) {
	int left = 0;
	int max_length = 0;
	int odd_count = 0;

	for(int right = 0; right < n; right++) {
		if(sequence[right] % 2 != 0) {	// 추가하는 원소가 홀수일 경우
			odd_count++;
		}

		while(odd_count > k) {	// 홀수의 개수는 k개 이하로 유지
			if(sequence[left] % 2 != 0) {
				odd_count--;
			}
			left++;
		}

		int current_length = (right - left + 1) - odd_count;	// 홀수는 제외
		max_length = max(max_length, current_length);
	}

	cout << max_length << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> sequence(n);

	for(int i = 0; i < n; i++) {
		cin >> sequence[i];
	}

	solution(n, k, sequence);

	return 0;
}