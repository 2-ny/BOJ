#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Lecture {
	int pay, time;
};

bool compare(const Lecture& a, const Lecture& b) {
	return a.time > b.time;	// time 내림차순 정렬
}
void solution(int n, int max_time, vector<Lecture>& lectures) {
	sort(lectures.begin(), lectures.end(), compare);

	int total_pay = 0;	
	priority_queue<int> max_pay;	// pay max-heap
	int index = 0;
	for(int current_time = max_time; current_time >= 1; current_time--) {
		for(int i = index; i < n; i++) {
			if(lectures[i].time >= current_time) {
				max_pay.push(lectures[i].pay);
				index++;
			}
			else {
				break;
			}
		}

		if(!max_pay.empty()) {
			total_pay += max_pay.top();
			max_pay.pop();
		}
	}

	cout << total_pay << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<Lecture> lectures;
	int max_time = 0;

	for(int i = 0; i < n; i++) {
		int pay, time;
		cin >> pay >> time;

		lectures.push_back({pay, time});
		max_time = max(max_time, time);
	}

	solution(n, max_time, lectures);

	return 0;
}