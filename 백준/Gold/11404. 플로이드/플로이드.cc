#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

void find_min_cost(int n, const vector<vector<pair<int, int>>>& edges) {
	vector<vector<int>> min_costs(n + 1, vector<int>(n + 1, INF));	// INF로 초기화

	for(int i = 1; i <= n; i++) {	// 자기 자신으로 가는 비용 0으로 초기화
		min_costs[i][i] = 0;
	}

	for(int start = 1; start <= n; start++) {
		for(auto [weight, end]: edges[start]) {
			min_costs[start][end] = min(min_costs[start][end], weight);
		}
	}

	for(int k = 1; k <= n; k++) {	// k: 경유 지점
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(min_costs[i][k] != INF && min_costs[k][j] != INF && min_costs[i][j] > min_costs[i][k] + min_costs[k][j]) {
					min_costs[i][j] = min_costs[i][k] + min_costs[k][j];
				}
			}
		}
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(min_costs[i][j] == INF) {	// i에서 j로 갈 수 없는 경우
				min_costs[i][j] = 0;
			}
			cout << min_costs[i][j] << " ";
		}
		cout << "\n";
	}
}

int main (){
	int n, m;
	cin >> n >> m;

	// edges[u] = {{w1, v1}, {w2, v2}, ...} w: 도시 u에서 v로 가는데 필요한 비용
	vector<vector<pair<int, int>>> edges(n + 1);
	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		edges[u].push_back({w, v});
	}

	find_min_cost(n, edges);

	return 0;
}