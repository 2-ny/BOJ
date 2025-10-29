#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n + 1);
	vector<int> in_degree(n + 1, 0);
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		in_degree[v]++;
	}

	queue<int> Q;
	for(int i = 1; i <= n; i++) {	// 1-based
		if(in_degree[i] == 0) {
			Q.push(i);
		}
	}

	vector<int> result;

	while(!Q.empty()) {
		int current_node = Q.front();
		Q.pop();

		for(auto next_node: adj[current_node]) {
			in_degree[next_node]--;

			if(in_degree[next_node] == 0) {
				Q.push(next_node);
			}
		}

		result.push_back(current_node);
	}

	for(auto student_number: result) {
		cout << student_number << " ";
	}
	cout << "\n";

	return 0;
}