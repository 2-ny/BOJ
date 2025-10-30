#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int find_min_cost(int current, int current_mask, int start, int n, const vector<vector<int>>& w, vector<vector<int>>& min_costs) {

	// 모든 도시 방문했을 때
	if(current_mask == (1 << n) - 1) {
		if(w[current][start] == 0) {	// start로 돌아가지 못하는 경우
			return INF;
		}

		return w[current][start];
	}

	// Memoization
	if(min_costs[current][current_mask] != -1) {
		return min_costs[current][current_mask];
	}

	// Recurrence(점화식)
	min_costs[current][current_mask] = INF;

	for(int next = 0; next < n; next++) {

		// next 방문 여부 확인
		if(!(current_mask & (1 << next))) {

			if(w[current][next] > 0) {	// current -> next 이동 가능한 경우
				int new_cost = w[current][next] + find_min_cost(next, (current_mask | (1 << next)), start, n, w, min_costs);

				min_costs[current][current_mask] = min(min_costs[current][current_mask], new_cost);
			}
		}
	}

	return min_costs[current][current_mask];
}

int main() {
	int n;
	cin >> n;

	vector<vector<int>> w(n, vector<int>(n));
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> w[i][j];
		}
	}

	int total_min = INF;
	int mask = 1 << n;
	vector<vector<int>> min_costs(n, vector<int>(mask, -1));	// min_costs[k][mask]: k 도시까지 방문했을 때 나머지 도시 거쳐 start로 돌아가는 최소 비용

	int start = 0;
	int start_mask = 1 << start;
	total_min = min(total_min, find_min_cost(start, start_mask, start, n, w, min_costs));

	cout << total_min << "\n";

	return 0;
}