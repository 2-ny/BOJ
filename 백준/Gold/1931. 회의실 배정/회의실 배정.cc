#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Time {
	int start, end;

	bool operator<(const Time& other) const {
		if(end == other.end) {
			return start < other.start;
		}
		return end < other.end;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<Time> info(n);

	int count = 0;

	for(int i = 0; i < n; i++) {
		cin >> info[i].start >> info[i].end;
	}

	sort(info.begin(), info.end());

	int end_time = -1;

	for(auto [start, end]: info) {
		if(start >= end_time) {
			count++;
			end_time = end;
		}
	}

	cout << count << "\n";

	return 0;
}