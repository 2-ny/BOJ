#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> make_sort(int n, const vector<vector<int>>& adj, vector<int>& in_degree) {
	queue<int> Q;
	vector<int> sorted_vector;

	for(int i = 1; i <= n; i++) {
		if(in_degree[i] == 0) {
			Q.push(i);
		}
	}

	while(!Q.empty()) {
		int current_node = Q.front();
		Q.pop();
		sorted_vector.push_back(current_node);

		for(auto next_node: adj[current_node]) {
			in_degree[next_node]--;

			if(in_degree[next_node] == 0) {
				Q.push(next_node);
			}
		}
	}

	return sorted_vector;
}

void find_min_time(int current_index, int w, int n, const vector<int>& sorted_vector, vector<int>& min_times, const vector<int>& times, const vector<vector<int>>& reverse_adj) {
	int current_node = sorted_vector[current_index];

	int pre_time = 0;
	for(auto parent: reverse_adj[current_node]) {
		pre_time = max(pre_time, min_times[parent]);
	}

	min_times[current_node] = pre_time + times[current_node];

	if(current_node == w) {
		cout << min_times[w] << "\n";
		return;
	}
	
	find_min_time(current_index + 1, w, n, sorted_vector, min_times, times, reverse_adj);

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int test_case;
	cin >> test_case;

	while(test_case > 0) {
		test_case--;

		int n, k;
		cin >> n >> k;

		vector<int> times(n + 1);

		for(int i = 1; i <= n; i++) {
			cin >> times[i];
		}

		vector<vector<int>> adj(n + 1);
		vector<vector<int>> reverse_adj(n + 1);
		vector<int> in_degree(n + 1, 0);

		for(int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;

			adj[x].push_back(y);
			reverse_adj[y].push_back(x);
			in_degree[y]++;
		}

		int w;
		cin >> w;

		vector<int> sorted_vector = make_sort(n, adj, in_degree);

		vector<int> min_times(n + 1);

		find_min_time(0, w, n, sorted_vector, min_times, times, reverse_adj);
	}

	return 0;
}