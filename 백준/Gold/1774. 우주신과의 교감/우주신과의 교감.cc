#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstdio>

using namespace std;

struct Edge {
	int u, v;
	double dist;

	bool operator<(const Edge& other) const {
		return dist < other.dist;
	}
};

struct UnionFind {
	vector<int> parent;
	int edges_count;

	UnionFind(int n) {
		parent.resize(n + 1);

		iota(parent.begin(), parent.end(), 0);

		edges_count = 0;
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

double find_min_dist(int n, vector<Edge>& edges, UnionFind& uf) {
	sort(edges.begin(), edges.end());

	double total_dist = 0;

	for(auto edge: edges) {
		if(uf.merge(edge.u, edge.v)) {
			total_dist+= edge.dist;
			uf.edges_count++;
		}

		if(uf.edges_count == n - 1) {
			break;
		}
	}

	return total_dist;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> infos(n + 1);

	for(int i = 1; i <= n ; i++) {
		cin >> infos[i].first >> infos[i].second;
	}

	UnionFind uf(n);
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		if(uf.merge(a, b)) {
			uf.edges_count++;
		}
	}

	vector<Edge> edges;

	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			double dx = infos[i].first - infos[j].first;
			double dy = infos[i].second - infos[j].second;

			double dist = sqrt(dx * dx + dy * dy);

			edges.push_back({i, j, dist});
		}
	}

	double min_dist = find_min_dist(n, edges, uf);

	printf("%.2f\n", min_dist);

	return 0;
}