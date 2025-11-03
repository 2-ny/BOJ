#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

void find_min_cycle(int v, const vector<vector<pair<int, int>>>& edges) {
	vector<vector<int>> min_dist(v + 1, vector<int>(v + 1, INF));

	for(int start = 1; start <= v; start++) {
		for(auto [dist, end]: edges[start]) {
			min_dist[start][end] = dist;
		}
		min_dist[start][start] = 0;
	}

	for(int k = 1; k <= v; k++) {
		for(int start = 1; start <= v; start++) {
			for(int end = 1; end <= v; end++) {
				if(min_dist[start][k] != INF && min_dist[k][end] != INF) {
					if(min_dist[start][end] > min_dist[start][k] + min_dist[k][end]) {
						min_dist[start][end] = min_dist[start][k] + min_dist[k][end];
					}
				}
			}
		}
	}

	int min_cycle = INF;
	for(int start = 1; start <= v; start++) {
		for(int end = 1; end <= v; end++) {
			if(start != end && min_dist[start][end] != INF && min_dist[end][start] != INF) {
				min_cycle = min(min_cycle, min_dist[start][end] + min_dist[end][start]);
			}
		}
	}

	if(min_cycle == INF) {
		cout << -1 << "\n";
		return;
	}
	
	cout << min_cycle << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int v, e;
	cin >> v >> e;

	vector<vector<pair<int, int>>> edges(v + 1);
	for(int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].push_back({c, b});
	}

	find_min_cycle(v, edges);

	return 0;
}