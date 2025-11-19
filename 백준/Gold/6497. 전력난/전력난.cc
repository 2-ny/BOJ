#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Edge {
	int u, v, dist;

	bool operator<(const Edge& other) const {
		return dist < other.dist;
	}
};

struct UnionFind {
	vector<int> parent;

	UnionFind(int m) {
		parent.resize(m);
		iota(parent.begin(), parent.end(), 0);
	}

	int find(int a) {
		if(parent[a] == a) {
			return a;
		}

		return parent[a] = find(parent[a]);
	}

	bool merge(int a, int b) {
		int rootA = find(a);
		int rootB = find(b);

		if(rootA != rootB) {
			parent[rootA] = rootB;
			return true;
		}

		return false;
	}
};

long long find_min_cost(int m, vector<Edge>& edges) {
	sort(edges.begin(), edges.end());

	int edges_count = 0;
	long long min_cost = 0;

	UnionFind uf(m);

	for(auto edge: edges) {
		if(uf.merge(edge.u, edge.v)) {
			edges_count++;
			min_cost += edge.dist;
		}

		if(edges_count == m - 1) {
			break;
		}
	}

	return min_cost;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int m, n;
	cin >> m >> n;

	while(!(m == 0 && n == 0)) {

		vector<Edge> edges;
		long long prev_cost = 0;

		for(int i = 0; i < n; i++) {
			int x, y, z;
			cin >> x >> y >> z;

			edges.push_back({x, y, z});
			prev_cost += z;
		}

		long long min_cost = find_min_cost(m, edges);

		cout << prev_cost - min_cost << "\n";

		cin >> m >> n;
	}

	return 0;
}