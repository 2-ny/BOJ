#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Time {
	int start, end;
};

bool compare(const Time& a, const Time& b) {
	if(a.start == b.start) {
		return a.end < b.end;
	}
	
	return a.start < b.start;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<Time> meetings(n);

	for(int i = 0; i < n; i++) {
		cin >> meetings[i].start >> meetings[i].end;
	}

	sort(meetings.begin(), meetings.end(), compare);

	priority_queue<int, vector<int>, greater<int>> end_time;

	end_time.push(meetings[0].end);

	int max_room = 1;

	for(int i = 1; i < n; i++) {
		int min_end_time = end_time.top();

		if(meetings[i].start >= min_end_time) {
			end_time.pop();
		}
		else {
			max_room++;
		}

		end_time.push(meetings[i].end);
	}

	cout << max_room << "\n";
	return 0;
}