#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	unordered_set<int> us;

	for(int i = 0; i < n; i++) {
		int term;
		cin >> term;

		us.insert(term);
	}

	vector<int> v;

	for(auto term: us) {
		v.push_back(term);
	}

	sort(v.begin(), v.end());

	for(auto term_ordered: v) {
		cout << term_ordered << "\n";
	}

	return 0;
}