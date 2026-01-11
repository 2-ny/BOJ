#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	if(n < 3) {
		cout << 0 << "\n";

		return 0;
	}

	vector<int> numbers(n);

	for(int i = 0; i < n; i++) {
		cin >> numbers[i];
	}

	sort(numbers.begin(), numbers.end());

	int count = 0;

	for(int i = 0; i < n; i++) {
		int target = numbers[i];

		int left = 0;
		int right = n - 1;

		while(left < right) {
			int sum = numbers[left] + numbers[right];
			
			if(left == i) {
				left++;
				continue;
			}

			if(right == i) {
				right--;
				continue;
			}

			if(sum == target) {
				count++;
				break;
			}

			if(sum > target) {
				right--;
			}
			else {
				left++;
			}
		}
	}

	cout << count << "\n";

	return 0;
}