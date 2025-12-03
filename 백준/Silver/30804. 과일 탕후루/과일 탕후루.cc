#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution(int n, vector<int>& fruits) {
	int left = 0, right = 0;
	int max_length = 0;
	vector<int> count(n + 1, 0);	// 1-based, 과일 개수 카운트;
	int kind = 0;

	for(right = 0; right < n; right++) {
		if(count[fruits[right]] == 0) {
			kind++;
		}
		count[fruits[right]]++;

		while(kind > 2) {
			count[fruits[left]]--;

			if(count[fruits[left]] == 0) {
				kind--;
			}

			left++;
		}

		max_length = max(max_length, right - left + 1);
	}

	cout << max_length << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> fruits(n);	// 0-based
	for(int i = 0; i < n; i++) {
		cin >> fruits[i];
	}

	solution(n, fruits);

	return 0;
}