#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

void find_min_cost(int c, int n, int max_new, const vector<pair<int, int>>& info, vector<int>& min_costs) {

	min_costs[0] = 0;

	for(int i = 1; i < c + max_new; i++) {
		for(int j = 1; j <= n; j++) {
			int cost = info[j].first;
			int new_c = info[j].second;

			if(i >= new_c) {
				min_costs[i] = min(min_costs[i], min_costs[i - new_c] + cost);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int c, n;
	cin >> c >> n;

	// info[k] = {cost, new}
	vector<pair<int, int>> info(n + 1);
	int max_new = 0;

	for(int i = 1; i <= n; i++) {
		int cost, new_c;
		cin >> cost >> new_c;

		info[i] = {cost, new_c};
		max_new = max(max_new, new_c);
	}

	vector<int> min_costs(c + max_new, INF);

	find_min_cost(c, n, max_new, info, min_costs);

	int min_cost = INF;
	for(int new_customer = c; new_customer < c + max_new; new_customer++) {
		min_cost = min(min_cost, min_costs[new_customer]);
	}

	cout << min_cost << "\n";

	return 0;
}
