#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void find_max_path(int current_node, const vector<vector<pair<int, int>>>& adj, vector<vector<int>>& max_path, vector<bool>& visited) {
	visited[current_node] = true;
	
	// leaf node일 경우(base case)
	if(adj[current_node].empty()) {
		max_path[current_node].push_back(0);
	}

	for(auto [weight, next_node]: adj[current_node]) {
		if(!visited[next_node]) {
			find_max_path(next_node, adj, max_path, visited);

			// next_node의 최대 경로와 가중치의 합
			int calc_max = max_path[next_node][0] + weight;

			max_path[current_node].push_back(calc_max);
		}
	}

	// 내림차순으로 정렬
	sort(max_path[current_node].begin(), max_path[current_node].end(), greater<int>());
}

void find_max_diameter(int n, const vector<vector<pair<int, int>>>& adj, const vector<vector<int>>& max_path) {
	int max_diameter = 0;

	for(int i = 1; i <= n; i++) {
		// 자식 노드가 2이상인 경우 
		if(adj[i].size() >= 2) {
			max_diameter = max(max_diameter, max_path[i][0] + max_path[i][1]);
		}

		// 자식 노드가 2이상이 아니여도 최대가 될 수 있음.
		max_diameter = max(max_diameter, max_path[i][0]);
	}

	cout << max_diameter << "\n";
}

int main() {
	int n;
	cin >> n;

	// adj[u][] = {w, v}: 부모 노드 u, 자식 노드 v, 가중치 w(1-based)
	vector<vector<pair<int, int>>> adj(n + 1);

	for(int i = 0; i < n - 1; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		adj[u].push_back({w, v});
	}


	// n = 1, 2인 경우 예외처리
	if(n == 1) {
		cout << 0 << "\n";
		return 0;
	}

	// max_path
	vector<vector<int>> max_path(n + 1);
	vector<bool> visited(n + 1, false);
	find_max_path(1, adj, max_path, visited); // 루트 노드(1) 부터 시작

	find_max_diameter(n, adj, max_path);

	return 0;
}