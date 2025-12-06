#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Delivery {
	int send, receive, num;
};

bool compare(const Delivery& a, const Delivery& b) {
	return a.receive < b.receive;
}

void solution(int n, int c, int m, vector<Delivery>& deliveries) {
	sort(deliveries.begin(), deliveries.end(), compare);

	int count = 0;
	vector<int> box_num(n + 1, 0);	// a -> b 배송 시 [a, b) 배열에 num 저장

	for(int i = 0; i < m; i++) {
		int send = deliveries[i].send;
		int receive = deliveries[i].receive;
		int num = deliveries[i].num;

		int max_load = 0;
		
		for(int j = send; j < receive; j++) {
			max_load = max(max_load, box_num[j]);
		}

		int can_load = min(num, c - max_load);

		for(int j = send; j < receive; j++) {
			box_num[j] += can_load;
		}

		count += can_load;
	}

	cout << count << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, c;	
	cin >> n >> c;

	int m;
	cin >> m;

	vector<Delivery> deliveries(m);

	for(int i = 0; i < m; i++) {
		cin >> deliveries[i].send >> deliveries[i].receive >> deliveries[i].num;
	}

	solution(n, c, m, deliveries);

	return 0;
}