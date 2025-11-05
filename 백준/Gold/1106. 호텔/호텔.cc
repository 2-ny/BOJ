#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

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
