#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int find_min_cost(int first_color, int n, const vector<vector<int>>& costs) {
	vector<vector<int>> min_costs(n + 1, vector<int>(3, INF));

	min_costs[1][first_color] = costs[1][first_color];

	for(int i = 2; i <= n; i++) {
		for(int color = 0; color < 3; color++) {
			if(i == n && color == first_color) {
				continue;
			}
			int prev_cost = min(min_costs[i - 1][(color + 1) % 3], min_costs[i - 1][(color + 2) % 3]);

			if(prev_cost != INF) {
				min_costs[i][color] = prev_cost + costs[i][color];
			}
		}
	}

	int min_cost = min(min_costs[n][(first_color + 1) % 3], min_costs[n][(first_color + 2) % 3]);
	
	return min_cost;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	// costs[i][0]: i번째를 R로 칠하는 비용(0: R, 1: G, 2: B)
	vector<vector<int>> costs(n + 1, vector<int>(3));
	for(int i = 1; i <= n; i++) {
		cin >> costs[i][0] >> costs[i][1] >> costs[i][2];
	}

	int min_cost = INF;

	// 1번 집이 R, G, B일 때 최소 비용 각각 구한 뒤 최종 최소 비용 찾기
	for(int first_color = 0; first_color < 3; first_color++) {
		min_cost = min(min_cost, find_min_cost(first_color, n, costs));
	}
	
	cout << min_cost << "\n";

	return 0;
}