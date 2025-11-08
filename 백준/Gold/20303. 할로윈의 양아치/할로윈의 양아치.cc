#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

void grouping(int index, int k, int& group_people, int& group_candies, const vector<int>& num_of_candies, const vector<vector<int>>& adj, vector<pair<int, int>>& groups, vector<bool>& visited) {
	
	visited[index] = true;
	group_people++;
	group_candies += num_of_candies[index];

	for(auto friends: adj[index]) {
		if(!visited[friends]) {
			grouping(friends, k, group_people, group_candies, num_of_candies, adj, groups, visited);
		}
	}
}

void find_min_people(int n, int k, int num_of_groups, int min_people, const vector<pair<int, int>>& groups) {

	vector<int> max_candies(k, -1);

	max_candies[0] = 0;

	for(int i = 0; i < num_of_groups; i++) {
		int group_people = groups[i].first;
		int group_candies = groups[i].second;

		for(int j = k - 1; j >= group_people; j--) {
			max_candies[j] = max(max_candies[j], max_candies[j - group_people] + group_candies);
		}
	}

	int answer = -1;
	for(int i = min_people; i < k; i++) {
		answer = max(answer, max_candies[i]);
	}

	cout << answer << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> num_of_candies(n + 1);	// 1-based
	for(int i = 1; i <= n; i++) {
		cin >> num_of_candies[i];
	}

	vector<vector<int>> adj(n + 1);	// 1-based
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<pair<int, int>> groups;
	vector<bool> visited(n + 1, false);

	for(int i = 1; i <= n; i++) {
		if(!visited[i]) {
			int group_candies = 0;
			int group_people = 0;

			grouping(i, k, group_people, group_candies, num_of_candies, adj, groups, visited);
			
			groups.push_back({group_people, group_candies});
		}
	}

	int num_of_groups = groups.size();
	int min_people = INF;	

	for(auto [people, candies]: groups) {
		min_people = min(min_people, people);
	}

	if(min_people >= k) {
		cout << 0 << "\n";
		return 0;
	}

	find_min_people(n, k, num_of_groups, min_people, groups);

	return 0;
}