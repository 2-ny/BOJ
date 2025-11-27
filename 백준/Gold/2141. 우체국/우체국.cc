#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void find_location(int n, long long total_people, vector<pair<int, long long >>& info) {
	sort(info.begin(), info.end());	// 마을 위치 오름차순으로 정렬

	long long accumulated_people = 0;

	for(auto [location, people]: info) {
		accumulated_people += people;

		if(accumulated_people >= (total_people + 1) / 2) {	// 올림
			cout << location << "\n";
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	// {마을 위치, 마을 인구수} 저장
	vector<pair<int, long long>> info(n);

	// 전체 인구수 저장(중간값 찾기 위해)
	long long total_people = 0;

	for(int i = 0; i < n; i++) {
		cin >> info[i].first >> info[i].second;

		total_people += info[i].second;
	}

	find_location(n, total_people, info);

	return 0;
}