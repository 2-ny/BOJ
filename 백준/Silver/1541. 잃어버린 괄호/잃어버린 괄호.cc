#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string line;
	cin >> line;

	stack<int> combine;
	int answer = 0;
	bool minus = false;
	
	for(int i = 0; i < line.length(); i++) {
		if(line[i] != '+' && line[i] != '-') {
			int num = line[i] - '0';
			combine.push(num);
			//cout << "push" << num << "\n";
		}

		// 마지막 숫자일 때도 연산에 포함
		if(line[i] == '+' || line[i] == '-' || i == line.length() - 1) {
			int operand = 0;
			int count = 0;
			while(!combine.empty()) {
				operand += combine.top() * pow(10, count);
				//cout << "operand" << operand << "\n";
				combine.pop();
				count++;
			}
			
			if(minus == true) {
				answer -= operand;
			}
			else {
				answer += operand;
			}

			if(line[i] == '-') {
				minus = true;
			}
		}
	}

	cout << answer << "\n";
	return 0;
}