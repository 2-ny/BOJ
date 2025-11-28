#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int day_max = 365;

struct Schedule {
	int start, end;
};

bool compare(const Schedule& a, const Schedule& b) {
	if(a.start == b.start) {
		return a.end > b.end;
	}

	return a.start < b.start;
}

void find_min_area(int n, vector<Schedule>& schedules) {
	sort(schedules.begin(), schedules.end(), compare);

	vector<int> calendar(day_max + 2, 0);	// 각 날짜의 일정 개수 저장, 366번 인덱스까지 접근

	// 달력 완성
	for(int i = 0; i < n; i++) {
		int start = schedules[i].start;
		int end = schedules[i].end;

		for(int j = start; j <= end; j++) {
			calendar[j]++;
		}
	}

	// 코팅지 면적 구하기
	bool schedules_continue = false;
	int start = -1; // 연속 일정 시작, -1로 연속된 일정 존재 여부 판단
	int max_schedule = 0;	// 최대 일정 -> 코팅지의 세로 길이
	int total_area = 0;	// 코팅지 면적 합 저장

	// 366번 인덱스까지 접근 -> 365일을 포함한 코팅지 계산 가능
	for(int i = 1; i <= day_max + 1; i++) {
		if(calendar[i] != 0 && !schedules_continue) {
			// 코팅지 시작
			schedules_continue = true;
			start = i;
			max_schedule = calendar[i];
		}
		else if(calendar[i] != 0 && schedules_continue) {
			max_schedule = max(max_schedule, calendar[i]);
		}
		else {
			// 일정 0 -> 일정 연속 끝
			schedules_continue = false;

			if(start != -1) {
				// 코팅지 면적 계산
				total_area += (i - start) * max_schedule;
				
				start = -1;
			}
		}
	}

	cout << total_area << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<Schedule> schedules(n);

	for(int i = 0; i < n; i++) {
		cin >> schedules[i].start >> schedules[i].end;
	}

	find_min_area(n, schedules);

	return 0;
}