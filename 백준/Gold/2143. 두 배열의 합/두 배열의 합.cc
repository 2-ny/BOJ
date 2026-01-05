#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_lower_bound(long long target, vector<long long>& sum_B) {
	int low = 0;
	int high = sum_B.size() - 1;

	int result = sum_B.size();

	while(low <= high) {
		int mid = low + (high - low) / 2;

		if(sum_B[mid] >= target) {
			result = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}

	return result;
}

int find_upper_bound(long long target, vector<long long>& sum_B) {
	int low = 0;
	int high = sum_B.size() - 1;

	int result = sum_B.size();

	while(low <= high) {
		int mid = low + (high - low) / 2;

		if(sum_B[mid] > target) {
			result = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}

	return result;
}

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

	sort(sum_A.begin(), sum_A.end());
	sort(sum_B.begin(), sum_B.end());

	int ptrA = 0;
	int ptrB = sum_B.size() - 1;
	long long answer = 0;

	while(ptrA < sum_A.size() && ptrB >= 0) {
		long long current_sum = sum_A[ptrA] + sum_B[ptrB];

		if(current_sum == t) {
			// 중복 개수 세기
			long long targetA = sum_A[ptrA];
			long long cntA = 0;

			while(ptrA < sum_A.size() && sum_A[ptrA] == targetA) {
				ptrA++;
				cntA++;
			}

			long long targetB = sum_B[ptrB];
			long long cntB = 0;

			while(ptrB >= 0 && sum_B[ptrB] == targetB) {
				ptrB--;
				cntB++;
			}

			answer += (cntA * cntB);
		}
		else if(current_sum < t) {
			ptrA++;
		}
		else {
			ptrB--;
		}
	}

	cout << answer << "\n";
	
	return 0;
}