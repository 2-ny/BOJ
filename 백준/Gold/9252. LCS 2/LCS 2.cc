#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

void solution(const string& s1, const string& s2) {
	int size1 = s1.length();
	int size2 = s2.length();

	// lcs[p][q]: s1의 p번째, s2의 q번째 문자까지의 LCS(1-based)
	vector<vector<int>> lcs_length(size1 + 1, vector<int>(size2 + 1, 0));

	for(int i = 1; i <= size1; i++) {
		for(int j = 1; j <= size2; j++) {
			if(s1[i - 1] == s2[j - 1]) {
				lcs_length[i][j] = lcs_length[i - 1][j - 1] + 1;
			}
			else {
				lcs_length[i][j] = max(lcs_length[i - 1][j], lcs_length[i][j - 1]);
			}
		}	
	}

	int max_length = lcs_length[size1][size2];
	cout << max_length << "\n";

	if(max_length > 0) {
		stack<char> lcs_stack;
		int i = size1;
		int j = size2;

		while(i > 0 && j > 0) {
			if(s1[i - 1] == s2[j - 1]) {
				lcs_stack.push(s1[i - 1]);
				i--;
				j--;
			}
			else if(lcs_length[i - 1][j] > lcs_length[i][j - 1]) {
				i--;
			}
			else {
				j--;
			}
		}

		while(!lcs_stack.empty()) {
			cout << lcs_stack.top();
			lcs_stack.pop();
		}
		cout << "\n";
	}
}

int main() {
	string s1, s2;

	cin >> s1;
	cin >> s2;

	solution(s1, s2);

	return 0;
}