#include <iostream>
#include <queue>

using namespace std;

void calc_minus(priority_queue<int, vector<int>, greater<int>>& pq_minus, bool& has_zero, int& total_sum) {

	while(pq_minus.size() > 1) {
		int min_1 = pq_minus.top();
		pq_minus.pop();

		int min_2 = pq_minus.top();
		pq_minus.pop();

		int tie = min_1 * min_2;
		total_sum += tie;
	}

	if(!pq_minus.empty() && !has_zero) {	// 우선순위 큐 사이즈 1일 경우 && 0이 없는 경우
		total_sum += pq_minus.top();
		pq_minus.pop();
	}

	return;
}

void calc_plus(priority_queue<int>& pq_plus, int& total_sum) {
	
	while(pq_plus.size() > 1) {
		int max_1 = pq_plus.top();
		pq_plus.pop();

		int max_2 = pq_plus.top();
		pq_plus.pop();

		int tie = max_1 * max_2;
		total_sum += tie;
	}

	if(!pq_plus.empty()) {
		total_sum += pq_plus.top();
		pq_plus.pop();
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);	
	cin.tie(NULL);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> pq_minus;	// 음수 저장
	priority_queue<int> pq_plus;	// 양수 저장
	
	int total_sum = 0;
	bool has_zero = false;

	for(int i = 0; i < n; i++) {
		int temp;
		cin >> temp;

		if(temp < 0) {
			pq_minus.push(temp);
		}
		else if(temp > 1) {	
			pq_plus.push(temp);
		}
		else if(temp == 1) {
			total_sum++;	// 1은 곱하면 손해
		}
		else {	// temp == 0
			has_zero = true;	// 음수의 개수가 홀수일 경우 0과 묶으면 최대가 됨.
		}
	}

	calc_minus(pq_minus, has_zero, total_sum);

	calc_plus(pq_plus, total_sum);

	cout << total_sum << "\n";

	return 0;
}