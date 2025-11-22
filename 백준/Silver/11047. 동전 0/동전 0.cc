#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void find_min_number(int n, int k, vector<int>& coins) {
	sort(coins.begin(), coins.end(), greater<int>());

	int count = 0;
	int current_value = 0;

	for(auto coin: coins) {
		while(coin <= k - current_value) {
			current_value += coin;
			count++;
		}
		if(current_value == k) {
			break;
		}
	}

	cout << count << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> coins(n);

	for(int i = 0; i < n; i++) {
		cin >> coins[i];
	}

	find_min_number(n, k, coins);

	return 0;
}