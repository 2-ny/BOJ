#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstdio>

using namespace std;

struct Edge {
	int u, v;
	double cost;

	bool operator<(const Edge& other) const {
		return cost < other.cost;
	}
};

struct UnionFind {
	vector<int> parent;

	UnionFind(int V) {
		parent.resize(V + 1);
		iota(parent.begin(), parent.end(), 0);
	}

	int find(int a) {
		if(parent[a] == a) {
			return a;
		}

		return parent[a] = find(parent[a]);
	}

	void merge(int rootA, int rootB) {
		if(rootA != rootB) {
			parent[rootA] = rootB;
		}
	}
};

double find_min_cost(int n, vector<Edge>& edges) {
	sort(edges.begin(), edges.end());
	
	UnionFind union_find(n);

	double total_cost = 0;
	int edges_count = 0;

	for(auto edge: edges) {
		int rootA = union_find.find(edge.u);
		int rootB = union_find.find(edge.v);

		if(rootA != rootB) {
			union_find.merge(rootA, rootB);
			total_cost += edge.cost;
			edges_count++;
		}

		if(edges_count == n - 1) {
			return total_cost;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<pair<double, double>> infos(n + 1);

	for(int i = 1; i <= n; i++) {
		cin >> infos[i].first >> infos[i].second;
	}

	vector<Edge> edges;

	for(int i = 1; i <= n; i++) {
		double Ax = infos[i].first;
		double Ay = infos[i].second;

		for(int j = i + 1; j <= n; j++) {
			double Bx = infos[j].first;
			double By = infos[j].second;
			
			double cost = pow(abs(Ax - Bx), 2) + pow(abs(Ay - By), 2);
			
			edges.push_back({i, j, sqrt(cost)});
		}
	}

	double min_cost = find_min_cost(n, edges);

	printf("%.2f\n", min_cost);

	return 0;
}