#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

void solution(int n, string& str) {
	int left = 0, right = 0;
	int max_length = 1;
	int kind = 1;

	unordered_map<char, int> count;

	for(char c = 'a'; c <= 'z'; c++) {
		count[c] = 0;
	}

	count[str[left]] = 1;

	for(right = 1; right < str.size(); right++) {
		if(count[str[right]] == 0) {
			kind++;
		}
		count[str[right]]++;

		while(kind > n) {
			count[str[left]]--;
			if(count[str[left]] == 0) {
				kind--;
			}
			left++;
		}

		max_length = max(max_length, right - left + 1);
	}

	cout << max_length;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	string str;
	cin >> str;

	solution(n, str);

	return 0;
}