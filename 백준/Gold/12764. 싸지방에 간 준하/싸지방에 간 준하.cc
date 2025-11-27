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
	return a.start < b.start;
}

void solution(int n, vector<Time>& time_info) {
	sort(time_info.begin(), time_info.end(), compare);

	// {종료 시간, 사용한 자리} min-heap
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> seats_using;
	// {자리 번호} min-heap
	priority_queue<int, vector<int>, greater<int>> seats_empty;

	// 자리별 이용 횟수
	vector<int> seats_count(n + 1, 0);

	int max_seats = 0;	// 현재까지 개설된 총 좌석 수

	for(int i = 0; i < n; i++) {
		int start = time_info[i].start;
		int end = time_info[i].end;

		// 1. 청소 -> 현재 이용자가 오기 전에 끝난 사람들을 모두 내보냄
		while(!seats_using.empty() && seats_using.top().first <= start) {
			seats_empty.push(seats_using.top().second);	// 자리 비움
			seats_using.pop();
		}

		// 2. 배정 -> 자리 앉히기
		int current_seat_index;

		if(seats_empty.empty()) {
			// 빈 자리가 없는 경우 새 자리 개설
			max_seats++;
			current_seat_index = max_seats;
		}
		else {
			// 가장 번호가 작은 자리 재사용
			current_seat_index = seats_empty.top();
			seats_empty.pop();
		}

		// 3. 등록 -> 사용 정보 업데이트
		seats_using.push({end, current_seat_index});
		seats_count[current_seat_index]++;
	}

	cout << max_seats << "\n";

	for(int i = 1; i <= max_seats; i++) {
		cout << seats_count[i] << " ";
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