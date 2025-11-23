#include <iostream>
#include <queue>

using namespace std;

void calc_minus(priority_queue<int, vector<int>, greater<int>>& pq_minus, bool& zero, int& total_sum) {
	
	if(pq_minus.empty()) {
		return;
	}
	else if(pq_minus.size() == 1) {
		if(zero == true) {
			// 0이 있을 경우 0과 묶는다.
			return;
		}

		total_sum += pq_minus.top();
		pq_minus.pop();

		return;
	}

	while(pq_minus.size() > 1) {
		int min_1 = pq_minus.top();
		pq_minus.pop();

		int min_2 = pq_minus.top();
		pq_minus.pop();

		int tie = min_1 * min_2;
		total_sum += tie;
	}

	// 우선순위 큐 사이즈가 홀수일 경우 -> 한 개 남음
	if(pq_minus.size() == 1 && zero == false) {
		total_sum += pq_minus.top();
		pq_minus.pop();
	}

	return;
}

void calc_plus(priority_queue<int>& pq_plus, int& total_sum) {
	
	if(pq_plus.empty()) {
		return;
	}
	else if(pq_plus.size() == 1) {
		total_sum += pq_plus.top();
		pq_plus.pop();

		return;
	}

	while(pq_plus.size() > 1) {
		int min_1 = pq_plus.top();
		pq_plus.pop();

		int min_2 = pq_plus.top();
		pq_plus.pop();

		int tie = min_1 * min_2;
		total_sum += tie;
	}

	if(pq_plus.size() == 1) {
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
	bool zero = false;

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
			total_sum++;
		}
		else {	// temp == 0 일 경우
			zero = true;	// 음수의 개수가 홀수일 경우 0과 묶으면 최대가 됨.
		}
	}

	calc_minus(pq_minus, zero, total_sum);

	calc_plus(pq_plus, total_sum);

	cout << total_sum << "\n";

	return 0;
}