#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<long long> count(m, 0);
	long long current_sum = 0;
	long long answer = 0;

	for(int i = 0; i < n; i++) {
		int term;
		cin >> term;

		current_sum = (current_sum + term) % m;

		if(current_sum == 0) {
			answer++;
		}

		count[current_sum]++;
	}

	for(int i = 0; i < m; i++) {
		if(count[i] > 1) {
			answer += (count[i] * (count[i] - 1)) / 2;
		}
	}

	cout << answer << "\n";

	return 0;
}