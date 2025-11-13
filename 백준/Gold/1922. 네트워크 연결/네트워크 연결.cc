#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Edge {
	int u, v, weight;

	bool operator <(const Edge& other) const {
		return weight < other.weight;
	}
};

struct DSU {
	vector<int> parent;
	DSU(int n) {
		parent.resize(n + 1);

		iota(parent.begin(), parent.end(), 0);
	}

	int find(int a) {
		if(parent[a] == a) {
			return parent[a];
		}

		return parent[a] = find(parent[a]);
	}

	void merge(int a, int b) {
		int root1 = find(a);
		int root2 = find(b);

		if(root1 != root2) {
			parent[root1] = root2;
		}
	}
};

long long min_cost(int V, vector<Edge>& edges) {
	sort(edges.begin(), edges.end());

	DSU dsu(V);

	long long cost = 0;
	int edges_count = 0;
	for(const auto& edge: edges) {
		if(dsu.find(edge.u) != dsu.find(edge.v)) {
			dsu.merge(edge.u, edge.v);

			cost += edge.weight;
			edges_count++;

			if(edges_count == V - 1) {
				break;
			}
		}
	}

	return cost;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<Edge> edges;

	for(int i = 0; i < m; i++) {
		int u, v, weight;
		cin >> u >> v >> weight;

		if(u != v) {
			edges.push_back({u, v, weight});
		}
	}

	cout << min_cost(n, edges) << "\n";

	return 0;
}