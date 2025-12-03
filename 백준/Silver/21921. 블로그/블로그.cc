#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution(int n, int x, vector<int>& visitors) {
	int sum = 0;
	// sum 초기값 구하기
	for(int i = 0; i < x; i++) {
		sum += visitors[i];
	}

	int max_sum = sum;
	int max_count = 1;

	for(int i = x; i < n; i++) {
		sum += visitors[i];
		sum -= visitors[i - x];

		if(sum > max_sum) {
			max_sum = sum;
			max_count = 1;
		}
		else if(sum == max_sum) {
			max_count++;
		}
	}

	if(max_sum == 0) {
		cout << "SAD" << "\n";
		return;
	}

	cout << max_sum << "\n";
	cout << max_count << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x;
	cin >> n >> x;

	vector<int> visitors(n);

	for(int i = 0; i < n; i++) {
		cin >> visitors[i];
	}

	solution(n, x, visitors);

	return 0;
}