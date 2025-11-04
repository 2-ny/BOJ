#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void find_order(int n, const vector<vector<int>>& info, vector<int>& in_degree) {
	priority_queue<int> Q;
	vector<int> order;
	
	for(int i = 1; i <= n; i++) {
		if(in_degree[i] == 0) {
			Q.push(- i);
		}
	}

	while(!Q.empty()) {
		int current = - Q.top();
		Q.pop();
		order.push_back(current);

		for(auto next: info[current]) {
			in_degree[next]--;

			if(in_degree[next] == 0) {
				Q.push(- next);
			}
		}
	}

	for(auto problem: order) {
		cout << problem << " ";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> info(n + 1);
	vector<int> in_degree(n + 1, 0);

	for(int i = 0; i < m; i++) {
		int prev, next;
		cin >> prev >> next;

		info[prev].push_back(next);
		in_degree[next]++;
	}

	for(int i = 1; i <= n; i++) {
		sort(info[i].begin(), info[i].end());
	}

	find_order(n, info, in_degree);

	return 0;
}