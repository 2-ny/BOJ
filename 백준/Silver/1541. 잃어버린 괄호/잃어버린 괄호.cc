#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string line;
	cin >> line;

	int operand = 0;
	int answer = 0;
	bool minus = false;
	
	for(int i = 0; i <= line.length(); i++) {

		if(line[i] == '+' || line[i] == '-' || i == line.length()) {

			if(minus == true) {
				answer -= operand;
			}
			else {
				answer += operand;
			}

			if(line[i] == '-') {
				minus = true;
			}

			operand = 0;
		}

		else {
			operand = (operand * 10) + (line[i] -'0');
		}
	}

	cout << answer << "\n";
	return 0;
}