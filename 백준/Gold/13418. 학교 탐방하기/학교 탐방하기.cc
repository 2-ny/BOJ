#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Road {
	int u, v, cost;	// cost: 0(오르막길), 1(내리막길)
};

struct Union_Find {
	vector<int> parent;

	Union_Find(int V) {
		parent.resize(V + 1);
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

		if(rootA == rootB) {
			return false;
		}

		parent[rootA] = rootB;
		return true;
	}
};

bool compare_worst_path(const Road& a, const Road& b) {
	return a.cost < b.cost;
}

bool compare_best_path(const Road& a, const Road& b) {
	return a.cost > b.cost;
}

long long get_fatigue(int n, int m, vector<Road>& roads, bool best) {
	if(!best) {	// 최악의 코스
		sort(roads.begin(), roads.end(), compare_worst_path);
	}
	else {	// 최선의 코스
		sort(roads.begin(), roads.end(), compare_best_path);
	}

	Union_Find uf(n);
	int edge_count = 0;
	int uphill_count = 0;

	for(auto [u, v, cost]: roads) {
		if(uf.merge(u, v)) {
			if(cost == 0) {
				uphill_count++;
			}

			edge_count++;

			if(edge_count == n) {
				break;
			}
		}
	}

	return (long long)uphill_count * uphill_count;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<Road> roads(m + 1);	// 입구와 1번 도로 간의 연결 관계 포함

	for(int i = 0; i <= m; i++) {
		cin >> roads[i].u >> roads[i].v >> roads[i].cost;
	}

	long long worst_fatigue = get_fatigue(n, m, roads, 0);
	long long best_fatigue = get_fatigue(n, m, roads, 1);

	cout << worst_fatigue - best_fatigue << "\n";

	return 0;
}