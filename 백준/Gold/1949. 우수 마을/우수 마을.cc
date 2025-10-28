#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void solution(int current_node, const vector<int>& population, const vector<vector<int>>& adj, vector<vector<int>>& dp, vector<bool>& visited) {
	
	visited[current_node] = true;
	
	dp[current_node][1] = population[current_node];

	for(auto next_node: adj[current_node]) {
		if(!visited[next_node]) {
			solution(next_node, population, adj, dp, visited);
			
			dp[current_node][0] += max(dp[next_node][0], dp[next_node][1]);
			dp[current_node][1] += dp[next_node][0];
		}
	}
}

int main() {
	int n;
	cin >> n;

	vector<int> population(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> population[i];
	}

	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<vector<int>> dp(n + 1, vector<int>(2, 0));

	vector<bool> visited(n + 1, false);

	solution(1, population, adj, dp, visited);

	int total_max = max(dp[1][0], dp[1][1]);
	cout << total_max << "\n";
	return 0;
}