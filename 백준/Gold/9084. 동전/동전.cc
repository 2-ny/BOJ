#include <iostream>
#include <vector>

using namespace std;

void solution(int n, int m, const vector<int>& values) {
	// case_count[j]: j원을 만들기 위한 모든 경우의 수
	vector<int> case_count(m + 1, 0);

	// 0원을 만드는 경우의 수는 1
	case_count[0] = 1;

	for(int i = 0; i < n; i++) {
		int value = values[i];

		for(int j = value; j <= m; j++) {
			case_count[j] = case_count[j] + case_count[j - value];
		}
	}

	cout << case_count[m] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int test_case;
	cin >> test_case;

	for(int count = 0; count < test_case; count++) {
		int n;
		cin >> n;

		vector<int> values(n);
		for(int i = 0; i < n; i++) {
			cin >> values[i];
		}

		int m;
		cin >> m;

		solution(n, m, values);
	}

	return 0;
}