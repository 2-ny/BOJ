#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find(int a, vector<int>& parent) {
	if(parent[a] == a) {
		return parent[a];
	}

	return parent[a] = find(parent[a], parent);
}

void merge(int a, int b, vector<int>& parent) {
	int root1 = find(a, parent);
	int root2 = find(b, parent);

	parent[root2] = root1;
}

void isInclude(int a, int b, vector<int>& parent) {
	int root1 = find(a, parent);
	int root2 = find(b, parent);

	if(root1 == root2) {
		cout << "YES" << "\n";
	}
	else {
		cout << "NO" << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> parent(n + 1);
	for(int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	for(int i = 0; i < m; i++) {
		int operation, a, b;
		cin >> operation >> a >> b;

		if(operation == 0) {
			merge(a, b, parent);
		}
		else if(operation == 1) {
			isInclude(a, b, parent);
		}
	}

	return 0;
}