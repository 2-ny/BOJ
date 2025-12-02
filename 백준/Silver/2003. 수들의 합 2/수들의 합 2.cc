#include <iostream>
#include <vector>

using namespace std;

void solution(int n, int m, vector<int>& sequence_A) {
	int count = 0;
	int start = 0;
	int end = 0;
	int sum = 0;

	while(true) {
		if(sum >= m) {
			sum -= sequence_A[start++];
		}
		else if(end == n) {
			// sum < m인데 더 이상 뒤로 갈 곳 없음 -> 종료
			break;
		}
		else {
			// sum < m && end < n
			sum += sequence_A[end++];
		}

		if(sum == m) {
			count++;
		}
	}

	cout << count << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> sequence_A(n);	// 0-based

	for(int i = 0; i < n; i++) {
		cin >> sequence_A[i];
	}

	solution(n, m, sequence_A);

	return 0;
}