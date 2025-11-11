#include <iostream>
#include <vector>

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

	parent[root1] = root2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> parent((n + 1));
	for(int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			int info;
			cin >> info;

			if(info == 1) {
				merge(i, j, parent);
			}
		}
	}

	vector<int> plan;
	int city;
	while(cin >> city) {
		plan.push_back(city);
	}

	int prev_city = plan[0];

	for(int i = 1; i < plan.size(); i++) {
		int curr_city = plan[i];
		
		if(find(curr_city, parent) != find(prev_city, parent)) {
			cout << "NO" << "\n";
			return 0;
		}
	}

	cout << "YES" << "\n";
	return 0;
}