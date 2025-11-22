#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void find_min_num(int n, int l, vector<int>& location) {
	sort(location.begin(), location.end());

	double start = 0;
	double end = 0;
	int count = 0;

	for(auto k: location) {
		if(k >= start && k <= end) {
			continue;
		}
		
		start = k - 0.5;
		end = start + l;
		count++;
	}

	cout << count << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, l;
	cin >> n >> l;

	vector<int> location(n);

	for(int i = 0; i < n; i++) {
		cin >> location[i];
	}

	find_min_num(n, l, location);

	return 0;
}