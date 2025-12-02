#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void find_max_weight(int n, vector<int>& ropes) {
	sort(ropes.begin(), ropes.end());

	int max_weight = 0;
	int ropes_num = n;

	for(int i = 0; i < n; i++) {
		max_weight = max(max_weight, ropes[i] * ropes_num);
		ropes_num--;
	}

	cout << max_weight << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> ropes(n);

	for(int i = 0; i < n; i++) {
		cin >> ropes[i];
	}

	find_max_weight(n, ropes);

	return 0;
}