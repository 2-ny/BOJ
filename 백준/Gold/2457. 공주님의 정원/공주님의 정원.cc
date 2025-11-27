#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Flower {
	int start, end;	// month * 100 + day로 변환해서 저장
};

// 시작일 기준 오름차순 정렬
bool compare(const Flower& a, const Flower& b) {
	return a.start < b.start;
}

void solution(int n, vector<Flower>& flowers) {
	sort(flowers.begin(), flowers.end(), compare);

	int current_end = 301;	// 현재 커버된 마지막 날짜 (3월 1일)
	int count = 0;	// 심은 꽃 개수
	int index = 0;	// 후보 탐색할 인덱스

	// 11월 30일을 넘기는 것이 목표
	while(current_end <= 1130) {
		int max_end = 0;	// 이번 턴에 갱신할 수 있는 최대 종료일
		bool found = false;	// 후보 있는지 체크
		
		while(index < n && flowers[index].start <= current_end) {
			max_end = max(max_end, flowers[index].end);
			found = true;
			index++;
		}

		// 후보가 없거나, 날짜가 안 늘어나는 경우 실패
		if(!found || max_end <= current_end) {
			cout << 0 << "\n";
			return;
		}

		current_end = max_end;	// 가장 늦게 지는 꽃 선택 확정
		count++;
	}

	cout << count << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<Flower> flowers;

	for(int i = 0; i < n; i++) {
		int start_month, start_day, end_month, end_day;
		cin >> start_month >> start_day >> end_month >> end_day;

		flowers.push_back({start_month * 100 + start_day, end_month * 100 + end_day});
	}

	solution(n, flowers);

	return 0;
}