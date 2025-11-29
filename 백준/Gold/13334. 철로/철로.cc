#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Location {
	int start, end;
};

bool compare(const Location& a, const Location& b) {
	if(a.end == b.end) {
		return a.start < b.start;
	}
	return a.end < b.end;	// end 오름차순
}

void find_max_people(int n, vector<Location>& locations, int d) {
	sort(locations.begin(), locations.end(), compare);

	// start min-heap
	priority_queue<int, vector<int>, greater<int>> min_start;

	int max_people = 0;

	for(int i = 0; i < n; i++) {
		int start = locations[i].start;
		int end = locations[i].end;
		int length = end - start;

		if(length > d) {
			continue;
		}

		min_start.push(start);

		while(!min_start.empty()) {
			if(min_start.top() < end - d) {
				min_start.pop();
			}
			else {
				break;
			}
		}

		max_people = max(max_people, (int)min_start.size());
	}

	cout << max_people << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<Location> locations;

	for(int i = 0; i < n; i++) {
		int home, office;
		cin >> home >> office;

		if(home < office) {
			locations.push_back({home, office});
		}
		else {
			locations.push_back({office, home});
		}
	}

	int d;
	cin >> d;

	find_max_people(n, locations, d);

	return 0;
}