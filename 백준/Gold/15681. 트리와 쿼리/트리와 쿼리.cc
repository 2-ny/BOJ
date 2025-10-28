#include <iostream>
#include <vector>

using namespace std;

void solution(int n, int current_node, const vector<vector<int>>& adj, vector<int>& count_node, vector<bool>& visited) {
	
	// current_node가 leaf node일 경우(base case)
	if(adj[current_node].size() == 1 && visited[adj[current_node][0]]) {
		count_node[current_node] = 1;
	}

	for(auto next_node : adj[current_node]) {
		if(!visited[next_node]) {
			visited[next_node] = true;
			solution(n, next_node, adj, count_node, visited);
			count_node[current_node] += count_node[next_node];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, r, q;
	cin >> n >> r >> q;

	// adj[u][v]: u -> v 간선(1-based)
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> query(q);
	for(int i = 0; i < q; i++) {
		cin >> query[i];
	}

	// count_node[i]: i를 루트로 하는 서브트리에 속한 정점의 수(1-based)
	vector<int> count_node(n + 1, 1);

	vector<bool> visited(n + 1, false);
	visited[r] = true;

	solution(n, r, adj, count_node, visited);

	for(auto u : query) {
		cout << count_node[u] << "\n";
	}

	return 0;
}