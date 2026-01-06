#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> A(n);
	vector<int> B(n);
	vector<int> C(n);
	vector<int> D(n);

	for(int i = 0; i < n; i++) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}

	vector<long long> sumAB;
	sumAB.reserve(n * n);

	vector<long long> sumCD;
	sumCD.reserve(n * n);

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			sumAB.push_back((long long)A[i] + B[j]);
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			sumCD.push_back((long long)C[i] + D[j]);
		}
	}

	sort(sumCD.begin(), sumCD.end());

	int left = 0;
	int right = n - 1;

	long long count = 0;

	for(auto val : sumAB) {
		long long target = -val;

		auto up = upper_bound(sumCD.begin(), sumCD.end(), target);
		auto low = lower_bound(sumCD.begin(), sumCD.end(), target);

		count += (up - low);
	}

	cout << count << "\n";

	return 0;
}