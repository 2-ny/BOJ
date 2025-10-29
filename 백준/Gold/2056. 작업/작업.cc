#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> make_sort(int n, vector<int>& in_degree, const vector<vector<int>>& adj) {
	queue<int> Q;
	vector<int> sorted_vector;

	for(int i = 1; i <= n; i++) {
		if(in_degree[i] == 0) {
			Q.push(i);
		}
	}

	while(!Q.empty()) {
		int current_work = Q.front();
		Q.pop();
		sorted_vector.push_back(current_work);

		for(auto next_work: adj[current_work]) {
			in_degree[next_work]--;

			if(in_degree[next_work] == 0) {
				Q.push(next_work);
			}
		}
	}

	return sorted_vector;
}

void find_min_time(int current_index, int n, const vector<int>& sorted_works, vector<int>& min_time, const vector<int>& times, const vector<vector<int>>& adj, const vector<vector<int>>& reverse_adj) {	
	if(current_index == n) { // sorted_works는 0-based
		int total_time = 0;
		for(auto time: min_time) {
			total_time = max(total_time, time);
		}

		cout << total_time << "\n";
		return;
	}
	
	int current_work = sorted_works[current_index];

	int max_parent_time = 0;
	for(auto parent: reverse_adj[current_work]) {
		max_parent_time = max(max_parent_time, min_time[parent]);
	}

	min_time[current_work] = max_parent_time + times[current_work];
	
	find_min_time(current_index + 1, n, sorted_works, min_time, times, adj, reverse_adj);
}

int main() {
	int n;
	cin >> n;

	vector<int> times(n + 1);
	vector<vector<int>> adj(n + 1);
	vector<vector<int>> reverse_adj(n + 1);
	vector<int> in_degree(n + 1);

	for(int i = 1; i <= n; i++) {	// 1-based
		int time, count;
		cin >> time >> count;
		times[i] = time;

		for(int j = 0; j < count; j++) {
			int u;
			cin >> u;

			adj[u].push_back(i);
			reverse_adj[i].push_back(u);
			in_degree[i]++;
		}
	}

	vector<int> sorted_works = make_sort(n, in_degree, adj);

	vector<int> min_time(n + 1, 0);
	
	find_min_time(0, n, sorted_works, min_time, times, adj, reverse_adj);

	return 0;
}