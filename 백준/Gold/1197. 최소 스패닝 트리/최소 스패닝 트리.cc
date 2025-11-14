#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Edge {
	int u, v;
	long long weight;

	bool operator<(const Edge& other) const {
		return weight < other.weight;
	}
};

struct DSU {
	vector<int> parent;

	DSU(int V) {
		parent.resize(V + 1);

		iota(parent.begin(), parent.end(), 0);
	}

	int find(int a) {
		if(parent[a] == a) {
			return a;
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

void find_min_cost(int v, vector<Edge>& edges) {
	sort(edges.begin(), edges.end());

	DSU dsu(v);

	long long cost = 0;
	int edges_count = 0;
	for(const auto edge: edges) {
		if(dsu.find(edge.u) != dsu.find(edge.v)) {
			dsu.merge(edge.u, edge.v);

			cost += edge.weight;
			edges_count++;

			if(edges_count == v - 1) {
				break;
			}
		}
	}

	cout << cost << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int v, e;
	cin >> v >> e;

	vector<Edge> edges;

	for(int i = 0; i < e; i++) {
		int a, b;
		long long c;

		cin >> a >> b >> c;

		edges.push_back({a, b, c});
	}

	find_min_cost(v, edges);

	return 0;
}