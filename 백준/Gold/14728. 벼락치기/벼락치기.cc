#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Chapter {
	int time, score;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, t;
	cin >> n >> t;

	vector<Chapter> chapters(n);

	for(int i = 0; i < n; i++) {
		cin >> chapters[i].time >> chapters[i].score;
	}

	vector<int> max_score(t + 1, 0);
	
	for(int i = 0; i < n; i++) {
		int time = chapters[i].time;
		int score = chapters[i].score;

		for(int j = t; j >= time; j--) {
			max_score[j] = max(max_score[j], max_score[j - time] + score);
		}
	}

	cout << max_score[t] << "\n";

	return 0;
}