#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <numeric>

using namespace std;

const int INF = numeric_limits<int>::max();

void solution(int k, const vector<int>& file_sizes) {
	// min_cost[i][j]: i번째 장부터 j번째 장까지 합치는 데 필요한 최소 비용
	vector<vector<int>> min_cost(k + 1, vector<int>(k + 1));

	// accumulate_sizes[i]: 1번째 장부터 i번째 장까지 파일 크기 합
	vector<int> accumulate_sizes(k + 1);

	for(int i = 1; i <= k; i++) {
		accumulate_sizes[i] = accumulate(file_sizes.begin() + 1, file_sizes.begin() + i + 1, 0);
	}

	// Base case: L = 2
	for(int i = 1; i <= k; i++) {
		min_cost[i][i] = 0;

		if(i < k) {
			min_cost[i][i + 1] = file_sizes[i] + file_sizes[i + 1];
		}
	}

	for(int L = 3; L <= k; L++) {	// L: 구간 길이
		for(int i = 1; i <= k - L + 1; i++) {	// i: 시작 점
			int j = i + L - 1;	// j: 끝 점
			min_cost[i][j] = INF;
			for(int k = i; k < j; k++) {
				int cost = min_cost[i][k] + min_cost[k + 1][j] + accumulate_sizes[j] - accumulate_sizes[i - 1];
				min_cost[i][j] = min(min_cost[i][j], cost);
			}
		}
	}

	cout << min_cost[1][k] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int test_case;
	cin >> test_case;

	while(test_case > 0) {
		int k;
		cin >> k;

		vector<int> file_sizes(k + 1);	// 1-based
		for(int i = 1; i <= k; i++) {
			cin >> file_sizes[i];
		}

		solution(k, file_sizes);

		test_case--;
	}

	return 0;
}