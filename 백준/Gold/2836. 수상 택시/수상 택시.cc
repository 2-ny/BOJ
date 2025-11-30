#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Taxi {
	int departure, arrival;
};

bool compare(const Taxi& a, const Taxi& b) {
	if(a.arrival == b.arrival) {
		return a.departure < b.departure;
	}

	return a.arrival < b.arrival;
}

void find_min_distance(int n, int m, vector<Taxi>& reverse_path) {

	if(reverse_path.empty()) {
		cout << m << "\n";
		return;
	}

	sort(reverse_path.begin(), reverse_path.end(), compare);

	long long total_distance = m;
	int max_departure = reverse_path[0].departure;
	int min_arrival = reverse_path[0].arrival;

	for(int i = 1; i < reverse_path.size(); i++) {

		int departure = reverse_path[i].departure;
		int arrival = reverse_path[i].arrival;

		if(arrival < max_departure) {
			max_departure = max(max_departure, departure);
		}

		else {
			total_distance += (long long)(max_departure - min_arrival) * 2;

			max_departure = departure;
			min_arrival = arrival;
		}
	}

	// 루프가 끝나고 남은 마지막 구간 처리
	total_distance += (long long)(max_departure - min_arrival) * 2;

	cout << total_distance << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<Taxi> reverse_path;

	for(int i = 0; i < n; i++) {
		int departure, arrival;
		cin >> departure >> arrival;

		if(arrival < departure) {
			reverse_path.push_back({departure, arrival});
		}
	}

	find_min_distance(n, m, reverse_path);

	return 0;
}