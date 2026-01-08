#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int total_score = 0;

	for(int i = 0; i < 10; i++) {
		int mushroom;
		cin >> mushroom;
		
		total_score += mushroom;

		if(total_score > 100) {
			int prev_score = total_score - mushroom;

			if(100 - prev_score < total_score - 100) {
				cout << prev_score << "\n";
			}
			else {
				cout << total_score << "\n";
			}

			return 0;
		}
	}

	cout << total_score << "\n";

	return 0;
}