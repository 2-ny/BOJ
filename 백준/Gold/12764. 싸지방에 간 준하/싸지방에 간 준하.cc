#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 1e9;

struct Time {
	int start, end;
};

bool compare(const Time& a, const Time& b) {
	if(a.start == b.start) {
		return a.end < b.end;
	}

	return a.start < b.start;
}

void solution(int n, vector<Time>& time_info) {
	sort(time_info.begin(), time_info.end(), compare);

	// {종료 시간, 사용한 자리} min-heap에 저장
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push({time_info[0].end});
	int max_seats = 1;

	vector<pair<int, int>> seats;	// 각 자리의 {종료 시간, 이용자 수} 저장, 1-based
	seats.push_back({INF, 0});	// 1-based 만들기 위해
	seats.push_back({time_info[0].end, 1});

	for(int i = 1; i < n; i++) {
		int min_end_time = pq.top();
		int start = time_info[i].start;
		int end = time_info[i].end;

		if(start < min_end_time) {
			max_seats++;
			seats.push_back({end, 1});
		}
		else {
			pq.pop();
			for(int i = 1; i <= max_seats; i++) {
				if(start > seats[i].first) {
					seats[i].first = end;
					seats[i].second += 1;
					break;
				}
			}
		}
		
		pq.push(end);
	}

	cout << max_seats << "\n";

	for(int i = 1; i <= max_seats; i++) {
		cout << seats[i].second << " ";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<Time> time_info(n);

	for(int i = 0; i < n; i++) {
		cin >> time_info[i].start >> time_info[i].end;
	}

	solution(n, time_info);

	return 0;
}