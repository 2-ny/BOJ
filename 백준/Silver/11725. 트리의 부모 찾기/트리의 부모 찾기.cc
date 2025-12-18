#include <iostream>
#include <vector>

using namespace std;

void find_parent(int parent, const vector<vector<int>>& adj, vector<int>& parents,vector<bool>& visited) {
	for(auto child : adj[parent]) {
		if(!visited[child]) {
			parents[child] = parent;

			visited[child] = true;

			find_parent(child, adj, parents, visited);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> adj(n + 1);

	for(int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> parents(n + 1);
	vector<bool> visited(n + 1, false);

	visited[1] = true;

	find_parent(1, adj, parents, visited);

	for(int i = 2; i <= n; i++) {
		cout << parents[i] << "\n";
	}

	return 0;
}