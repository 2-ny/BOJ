#include <iostream>
#include <vector>

using namespace std;

const long long INF = 1e18;

struct Edge {
	int u, v, weight;
};

bool find_minus_cycle(int start_node, int n, const vector<Edge>& edges, vector<long long>& dist) {
	dist.assign(n + 1, INF);
	dist[start_node] = 0;

	// n - 1번 수행
	for(int i = 0; i < n - 1; i++) {
		for(const auto& edge: edges) {
			if(dist[edge.u] == INF) {
				continue;
			}

			if(dist[edge.v] > dist[edge.u] + edge.weight) {
				dist[edge.v] = dist[edge.u] + edge.weight;
			}
		}
	}

	// n번째 다시 모든 간선 조사
	for(const auto& edge: edges) {
		if(dist[edge.u] == INF) {
			continue;
		}

		if(dist[edge.v] > dist[edge.u] + edge.weight) {
			// 계속 감소 -> 음수 사이클
			return true;
		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<Edge> edges;

	for(int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		edges.push_back({a, b, c});
	}

	vector<long long> dist;

	if(find_minus_cycle(1, n, edges, dist)) {
		cout << -1 << "\n";
		return 0;
	}
	
	for(int i = 2; i <= n; i++) {
		if(dist[i] == INF) {
			cout << -1 << "\n";
			continue;
		}
		cout << dist[i] << "\n";
	}

	return 0;
}