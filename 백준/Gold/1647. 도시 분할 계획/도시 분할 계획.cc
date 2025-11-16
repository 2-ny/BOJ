#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

struct Edge {
	int u, v, weight;

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

	void merge(int root1, int root2) {
		if(root1 != root2) {
			parent[root1] = root2;
		}
	}
};

long long find_min_cost(int n, vector<Edge>& edges) {
	sort(edges.begin(), edges.end());

	DSU dsu(n);

	if(n == 2) {
		return 0;
	}

	long long total_cost = 0;
	int edges_count = 0;

	for(auto edge: edges) {
		int root1 = dsu.find(edge.u);
		int root2 = dsu.find(edge.v);

		if(root1 != root2) {
			dsu.merge(root1, root2);

			total_cost += edge.weight;
			edges_count++;
		}

		if(edges_count == n - 2) {
			return total_cost;
		}
	}
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

		edges.push_back({u, v, weight});
	}

	cout << find_min_cost(n, edges) << "\n";

	return 0;
}