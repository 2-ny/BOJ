#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int find(int place, vector<int>& parent) {
	if(parent[place] == place) {
		return place;
	}

	return parent[place] = find(parent[place], parent);
}

void merge(int u, int v, vector<int>& parent) {
	u = find(u, parent);
	v = find(v, parent);

	if(u != v) {
		parent[u] = v;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, l;
	cin >> n >> l;

	vector<int> parent(l + 1);
	iota(parent.begin(), parent.end(), 0);

	vector<bool> visited(l + 1, false);

	for(int i = 1; i <= n; i++) {
		int u, v;
		cin >> u >> v;

		if(!visited[u]) {
			visited[u] = true;
			merge(u, v, parent);
			cout << "LADICA" << "\n";
		}
		else if(!visited[v]) {
			visited[v] = true;
			merge(v, u, parent);
			cout << "LADICA" << "\n";
		}
		else {
			int rootU = find(u, parent);
			if(!visited[rootU]) {
				visited[rootU] = true;
				merge(u, v, parent);
				cout << "LADICA" << "\n";
			}

			else {
				int rootV = find(v, parent);
				if(!visited[rootV]) {
					visited[rootV] = true;
					merge(v, u, parent);
					cout << "LADICA" << "\n";
				}
				else {
					cout << "SMECE" << "\n";
				}
			}
		}
	}

	return 0;
}