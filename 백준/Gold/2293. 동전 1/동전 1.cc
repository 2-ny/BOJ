#include <iostream>
#include <vector>

using namespace std;

void solution(int n, int k, const vector<int>& values) {
	// case_count[j]: 가치가 j일 때의 경우의 수
	vector<int> case_count(k + 1);
	
	// 가치가 0인 경우의 수: 1가지(모든 동전 선택 X)
	case_count[0] = 1;

	for(int i = 0; i < n; i++) {
		int value = values[i];

		for(int j = value; j <= k; j++) {
			case_count[j] = case_count[j] + case_count[j - value];
		}
	}

	cout << case_count[k] << "\n";
}

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> values(n);

	for(int i = 0; i < n; i++) {
		cin >> values[i];
	}

	solution(n, k, values);

	return 0;
}