#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Problem {
	int deadline, cupNoodle;
};

bool compare(const Problem& a, const Problem& b) {
	return a.deadline < b.deadline;
}

void find_max_cupNoodles(int n, int max_deadline, vector<Problem>& problems) {
	sort(problems.begin(), problems.end(), compare);	// deadline 오름차순

	priority_queue<int, vector<int>, greater<int>> cupNoodles;	// 컵라면 min-heap

	for(auto problem: problems) {
		cupNoodles.push(problem.cupNoodle);

		if(cupNoodles.size() > problem.deadline) {
			cupNoodles.pop();
		}
	}

	int max_cupNoodles = 0;

	while(!cupNoodles.empty()) {
		max_cupNoodles += cupNoodles.top();
		cupNoodles.pop();
	}

	cout << max_cupNoodles << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<Problem> problems(n);	// 0-based
	int max_deadline = 0;

	for(int i = 0; i < n; i++) {
		cin >> problems[i].deadline >> problems[i].cupNoodle;

		max_deadline = max(max_deadline, problems[i].deadline);
	}

	find_max_cupNoodles(n, max_deadline, problems);

	return 0;
}