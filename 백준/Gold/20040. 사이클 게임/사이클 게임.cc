#include <iostream>
#include <vector>

using namespace std;

int find(int x, vector<int>& parent) {
	if(parent[x] == x) {
		return x;
	}

	return parent[x] = find(parent[x], parent);
}

void merge(int u, int v, vector<int>& parent) {
	int root1 = find(u, parent);
	int root2 = find(v, parent);

	parent[root2] = root1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> parent(n);
	for(int i = 0; i < n; i++) {
		parent[i] = i;
	}

	int count = 1;

	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		if(find(u, parent) == find(v, parent)) {
			cout << count << "\n";
			return 0;
		}

		merge(u, v, parent);
		count++;
	}

	cout << 0 << "\n";

	return 0;
}