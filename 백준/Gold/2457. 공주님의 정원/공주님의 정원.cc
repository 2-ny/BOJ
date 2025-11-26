#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Day {
	int start_month, start_day, end_month, end_day;
};

bool compare(const Day& a, const Day& b) {
	if(a.start_month == b.start_month) {
		return a.start_day < b.start_day;
	}

	return a.start_month < b.start_month;
}

void solution(int n, vector<Day>& info) {
	sort(info.begin(), info.end(), compare);

	// max-heap에 {마지막 달, 마지막 날} 저장
	priority_queue<pair<int, int>> pq;
	int count = 0;	// 선택한 꽃 개수 count
	int start_num = 0;

	for(int i = 0; i < n; i++) {
		if(info[i].start_month < 3 || (info[i].start_month == 3 && info[i].start_day == 1)) {
			pq.push({info[i].end_month, info[i].end_day});
			start_num++;
		}

		else {
			break;
		}
	}

	int last_month = 3;
	int last_day = 1;

	while(!pq.empty()) {
		last_month = pq.top().first;
		last_day = pq.top().second;
		pq.pop();
		count++;

		if(last_month == 12) {
			break;
		}

		for(int i = start_num; i < n; i++) {
			if(info[i].start_month < last_month || (info[i].start_month == last_month && info[i].start_day <= last_day)) {
				pq.push({info[i].end_month, info[i].end_day});
				start_num++;
			}
			
			else {
				break;
			}
		}
	}
	
	if(last_month != 12) {
		cout << 0 << "\n";
		return;
	}

	cout << count << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<Day> info;

	for(int i = 0; i < n; i++) {
		int start_month, start_day, end_month, end_day;
		cin >> start_month >> start_day >> end_month >> end_day;

		info.push_back({start_month, start_day, end_month, end_day});
	}

	solution(n, info);

	return 0;
}