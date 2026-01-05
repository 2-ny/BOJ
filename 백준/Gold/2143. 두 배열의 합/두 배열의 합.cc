#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long t;
	cin >> t;

	int n;
	cin >> n;

	vector<int> sequence_A(n);

	for(int i = 0; i < n; i++) {
		cin >> sequence_A[i];
	}

	int m;
	cin >> m;

	vector<int> sequence_B(m);

	for(int i = 0; i < m; i++) {
		cin >> sequence_B[i];
	}

	vector<long long> sum_A;

	for(int i = 0; i < n; i++) {
		long long current_sum = 0;

		for(int j = i; j < n; j++) {
			current_sum += sequence_A[j];
			sum_A.push_back(current_sum);
		}
	}

	vector<long long> sum_B;

	for(int i = 0; i < m; i++) {
		long long current_sum = 0;

		for(int j = i; j < m; j++) {
			current_sum += sequence_B[j];
			sum_B.push_back(current_sum);
		}
	}

	sort(sum_B.begin(), sum_B.end());

	long long count = 0;

	for(auto a : sum_A) {
		long long target = t - a;

		auto low = lower_bound(sum_B.begin(), sum_B.end(), target);
		auto up = upper_bound(sum_B.begin(), sum_B.end(), target);

		count += (up - low);
	}

	cout << count << "\n";

	return 0;
}