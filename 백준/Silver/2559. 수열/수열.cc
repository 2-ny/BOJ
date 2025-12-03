#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution(int n, int k, vector<int>& sequence) {
	int sum = 0;

	for(int i = 0; i < k; i++) {
		sum += sequence[i];
	}

	int max_sum = sum;
	int start = 0, end = k;	// 구간: [start, end)

	while(true) {
		if(end == n) {	// 더 이상 뒤로 갈 곳 없음 -> 종료
			break;
		}
		sum -= sequence[start++];
		sum += sequence[end++];

		max_sum = max(max_sum, sum);
	}

	cout << max_sum << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> sequence(n);

	for(int i = 0; i < n; i++) {
		cin >> sequence[i];
	}

	solution(n, k, sequence);

	return 0;
}