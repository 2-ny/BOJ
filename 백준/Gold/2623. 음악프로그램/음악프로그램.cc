#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void sorted_singers(int n, const vector<vector<int>>& singers, vector<int>& in_degree) {
	queue<int> Q;
	vector<int> answer;

	for(int i = 1; i <= n; i++) {
		if(in_degree[i] == 0) {
			Q.push(i);
		}
	}

	while(!Q.empty()) {
		int parent = Q.front();
		Q.pop();
		answer.push_back(parent);

		for(auto child: singers[parent]) {
			in_degree[child]--;

			if(in_degree[child] == 0) {
				Q.push(child);
			}
		}
	}

	if(answer.size() != n) {
		cout << 0 << "\n";
		return;
	}
	
	for(auto singer: answer) {
		cout << singer << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> pd(m);
	vector<vector<int>> singers(n + 1);
	vector<int> in_degree(n + 1, 0);

	for(int i = 0; i < m; i++) {
		int k;
		cin >> k;

		for(int j = 0; j < k; j++) {
			int s;
			cin >> s;
			pd[i].push_back(s);
		}

		for(int j = 0; j < k - 1; j++) {
			singers[pd[i][j]].push_back(pd[i][j + 1]);
			in_degree[pd[i][j + 1]]++;
		}
	}

	sorted_singers(n, singers, in_degree);

	return 0;
}