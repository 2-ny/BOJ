#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void find_max_size(int current_node, const vector<int>& weights, const vector<vector<int>>& edges, vector<vector<int>>& max_size, vector<bool>& visited) {
	visited[current_node] = true;

	max_size[current_node][1] = weights[current_node];

	for(auto child_node: edges[current_node]) {
		if(!visited[child_node]) {
			find_max_size(child_node, weights, edges, max_size, visited);

			max_size[current_node][0] += max(max_size[child_node][0], max_size[child_node][1]);
			max_size[current_node][1] += max_size[child_node][0];
		}
	}
}

void find_path(int current_node, int& current_size, int n, const vector<int>& weights, const vector<vector<int>>& edges, vector<vector<int>>& max_size, vector<int>& path, vector<bool>& visited) {
	visited[current_node] = true;

	if(current_size == 0) {
		for(int i = 1; i <= n; i++) {
			if(path[i] == 1) {
				cout << i << " ";
			}
		}

		cout << "\n";
		return;
	}

	for(auto child_node: edges[current_node]) {
		if(!visited[child_node] && current_size != 0) {
			if(path[current_node] == 0 && max_size[child_node][1] > max_size[child_node][0]) {
				// child_node -> 1
				path[child_node] = 1;
				current_size -= weights[child_node];
			}
			// 나머지 경우는 모두 child_node -> 0
			find_path(child_node, current_size, n, weights, edges, max_size, path, visited);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> weights(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> weights[i];
	}

	vector<vector<int>> edges(n + 1);
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;

		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	vector<vector<int>> max_size(n + 1, vector<int>(2, 0));
	vector<bool> visited(n + 1, false);

	find_max_size(1, weights, edges, max_size, visited);

	int total_size = max(max_size[1][0], max_size[1][1]);
	cout << total_size << "\n";

	vector<int> path(n + 1, 0);
	int current_size = total_size;
	
	fill(visited.begin(), visited.end(), false);

	if(max_size[1][1] > max_size[1][0]) {
		path[1] = 1;
		current_size -= weights[1];
	}

	find_path(1, current_size, n, weights, edges, max_size, path, visited);

	return 0;
}