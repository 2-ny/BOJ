#include <iostream>
#include <queue>

using namespace std;

void solution(int sequence_sum, priority_queue<int, vector<int>, greater<int>>& negative_min_q, priority_queue<int>& positive_max_q) {

	while(negative_min_q.size() > 1) {
		int minA = negative_min_q.top();
		negative_min_q.pop();

		int minB = negative_min_q.top();
		negative_min_q.pop();

		sequence_sum += (minA * minB);
	}

	if(!negative_min_q.empty()) {
		sequence_sum += negative_min_q.top();
		negative_min_q.pop();
	}

	while(positive_max_q.size() > 1) {
		int maxA = positive_max_q.top();
		positive_max_q.pop();

		int maxB = positive_max_q.top();
		positive_max_q.pop();

		sequence_sum += (maxA * maxB);
	}

	if(!positive_max_q.empty()) {
		sequence_sum += positive_max_q.top();
		positive_max_q.pop();
	}
	 
	cout << sequence_sum << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> negative_min_q;	// 음수 min-heap
	priority_queue<int> positive_max_q;	// 1 보다 큰 양수 max-heap

	int sequence_sum = 0;

	for(int i = 0; i < n; i++) {
		int term;
		cin >> term;

		if(term <= 0) {
			negative_min_q.push(term);
		}
		else if(term > 1) {
			positive_max_q.push(term);
		}
		else {
			// term == 1
			sequence_sum++;
		}
	}

	solution(sequence_sum, negative_min_q, positive_max_q);

	return 0;
}