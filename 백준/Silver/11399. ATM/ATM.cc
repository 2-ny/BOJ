#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void find_min_time(int n, vector<int>& wait_time) {
	sort(wait_time.begin(), wait_time.end());

	int total_time = 0;
	int waiting = n;

	for(int i = 0; i < n; i++) {
		total_time += wait_time[i] * waiting;

		waiting--;
	}

	cout << total_time << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> wait_time(n);	// 0-based
	for(int i = 0; i < n; i++) {
		cin >> wait_time[i];
	}

	find_min_time(n, wait_time);

	return 0;
}