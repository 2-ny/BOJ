#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

void find_path(int start, int end, const vector<vector<int>>& layover, vector<int>& path) {
	int k = layover[start][end];

	if(k == -1) {
		return;
	}

	find_path(start, k, layover, path);
	path.push_back(k);
	find_path(k, end, layover, path);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	// costs[u][v] = c -> u에서 v로 가는 비용(최솟값)
	vector<vector<int>> costs(n + 1, vector<int>(n + 1, INF));

	for(int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		costs[a][b] = min(costs[a][b], c);
	}

	vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));

	for(int i = 1; i <= n; i++) {
		dist[i][i] = 0;

		for(int j = 1; j <= n; j++) {
			if(costs[i][j] != INF) {
				dist[i][j] = costs[i][j];
			}
		}
	}

	vector<vector<int>> layover(n + 1, vector<int>(n + 1, -1));

	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(dist[i][k] != INF && dist[k][j] != INF) {
					if(dist[i][j] > dist[i][k] + dist[k][j]) {
						dist[i][j] = dist[i][k] + dist[k][j];
						layover[i][j] = k;
					}
				}
			}
		}
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(dist[i][j] == INF) {
				cout << 0 << " ";
			}
			else {
				cout << dist[i][j] << " ";
			}
		}
		cout << "\n";
	}

	vector<int> path;

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(dist[i][j] == INF || dist[i][j] == 0) {
				cout << 0 << "\n";
				continue;
			}

			path.clear();

			path.push_back(i);
			find_path(i, j, layover, path);
			path.push_back(j);

			cout << path.size() << " ";

			for(auto vertex: path) {
				cout << vertex << " ";
			}
			
			cout << "\n";
		}
	}

	return 0;
}