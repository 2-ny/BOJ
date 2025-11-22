#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> A(n);
	vector<int> B(n);

	for(int i = 0; i < n; i++) {
		cin >> A[i];
	}

	for(int i = 0; i < n; i++) {
		cin >> B[i];
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<int>());

	int answer = 0;
	for(int i = 0; i < n; i++) {
		answer += A[i] * B[i];
	}

	cout << answer << "\n";

	return 0;
}