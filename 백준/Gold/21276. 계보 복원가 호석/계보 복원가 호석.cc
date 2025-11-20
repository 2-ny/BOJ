#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	
	vector<string> people(n);
	unordered_map<string, int> people_num;
	vector<int> in_degree(n);

	for(int i = 0; i < n; i++) {
		cin >> people[i];
	}

	sort(people.begin(), people.end());

	for(int i = 0; i < n; i++) {
		people_num[people[i]] = i;
		in_degree[i] = 0;
	}

	int m;
	cin >> m;

	vector<vector<int>> child_cand(n);

	for(int i = 0; i < m; i++) {
		string x, y;
		cin >> x >> y;

		int x_num = people_num[x];
		int y_num = people_num[y];

		in_degree[x_num]++;
		child_cand[y_num].push_back(x_num);
	}

	int roots_count = 0;
	vector<int> roots;

	for(int i = 0; i < n; i++) {
		if(in_degree[i] == 0) {
			roots_count++;
			roots.push_back(i);
		}
	}

	cout << roots_count << "\n";
	for(auto root: roots) {
		cout << people[root] << " ";
	}
	cout << "\n";

	for(int i = 0; i < n; i++) {
		cout << people[i] << " ";

		sort(child_cand[i].begin(), child_cand[i].end());
		int childs_count = 0;
		vector<int> real_child;

		for(auto child_num: child_cand[i]) {
			if(in_degree[child_num] == in_degree[i] + 1) {
				childs_count++;
				real_child.push_back(child_num);
			}
		}

		cout << childs_count << " ";

		for(auto child_num: real_child) {
			cout << people[child_num] << " ";
		}
		cout << "\n";
	}

	return 0;
}