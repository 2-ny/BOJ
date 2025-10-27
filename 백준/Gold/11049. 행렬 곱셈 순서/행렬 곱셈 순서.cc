#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

void solution(int n, const vector<int>& rows) {
	// min_count[i][j]: i번째 행렬부터 j번째 행렬까지 모두 곱하는데 필요한 최소 곱셈 연산 횟수
	vector<vector<int>> min_count(n + 1, vector<int>(n + 1, 0));	// 1-based

	if(n >= 2) {
		for(int L = 2; L <= n; L++) {	// L: 구간의 길이
			for(int i = 1; i <= n - L + 1; i++) {	
				int j = i + L - 1;
				min_count[i][j] = INF;
				for(int k = i; k < j; k++) {
					min_count[i][j] = min(min_count[i][j], min_count[i][k] + min_count[k + 1][j] + rows[i] * rows[k + 1] * rows[j + 1]);
				}
			}
		}
	}

	cout << min_count[1][n] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> rows(n + 2);	// 1-based, 1 ~ n + 1 => n + 2개
	for(int i = 1; i <= n; i++) {
		cin >> rows[i] >> rows[i + 1];
	}

	solution(n, rows);

	return 0;
}