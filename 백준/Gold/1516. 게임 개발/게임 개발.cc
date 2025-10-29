#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> make_sort(int n, const vector<int>& times, const vector<vector<int>>& adj, vector<int>& in_degree) {
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

void find_min_times(int current_index, int n, const vector<int>& times, const vector<vector<int>>& reverse_adj, const vector<int>& sorted_building, vector<int>& min_times) {
	
	if(current_index == n) {	// 0-based
		for(int i = 1; i <= n; i++) {
			cout << min_times[i] << "\n";
		}
		
		return;
	}

	int current_building = sorted_building[current_index];
	
	min_times[current_building] = times[current_building];

	int pre_time = 0;
	for(auto parent: reverse_adj[current_building]) {
		pre_time = max(pre_time, min_times[parent]);
	}

	min_times[current_building] = pre_time + times[current_building];

	find_min_times(current_index + 1, n, times, reverse_adj,  sorted_building, min_times);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> times(n + 1);
	vector<vector<int>> adj(n + 1);
	vector<vector<int>> reverse_adj(n + 1);
	vector<int> in_degree(n + 1, 0);

	for(int i = 1; i <= n; i++) {
		cin >> times[i];

		int info;
		cin >> info;
		
		while(info != -1) {
			adj[info].push_back(i);
			reverse_adj[i].push_back(info);
			in_degree[i]++;

			cin >> info;
		}
	}

	vector<int> sorted_building = make_sort(n, times, adj, in_degree);

	vector<int> min_times(n + 1);

	find_min_times(0, n, times, reverse_adj, sorted_building, min_times);

	return 0;
}