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
			sumCD.push_back((long long)C[i] + D[j]);
		}
	}

	sort(sumAB.begin(), sumAB.end());
	sort(sumCD.begin(), sumCD.end());

	int left = 0;
	int right = sumCD.size() - 1;

	long long count = 0;

	while(left < sumAB.size() && right >= 0) {
		long long s1 = sumAB[left];
		long long s2 = sumCD[right];
		long long current_sum = s1 + s2;

		if(current_sum == 0) {
			long long cnt1 = 0;
			while(left < sumAB.size() && sumAB[left] == s1) {
				cnt1++;
				left++;
			}

			long long cnt2 = 0;
			while(right >= 0 && sumCD[right] == s2) {
				cnt2++;
				right--;
			}

			count += (cnt1 * cnt2);
		}

		else if(current_sum > 0) {
			right--;
		}
		else {
			left++;
		}
	}

	cout << count << "\n";

	return 0;
}