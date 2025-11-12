#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string find(string str, unordered_map<string, string>& map) {
	if(map[str] == str) {
		return map[str];
	}

	return map[str] = find(map[str], map);
}

void merge(string str1, string str2, unordered_map<string, string>& map, unordered_map<string, int>& count) {
	string root1 = find(str1, map);
	string root2 = find(str2, map);

	map[root2] = root1;
	count[root1] += count[root2];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int test_case;
	cin >> test_case;

	while(test_case > 0) {
		int f;
		cin >> f;

		unordered_map<string, string> map;
		unordered_map<string, int> count;

		for(int i = 0; i < f; i++) {
			string str1, str2;
			cin >> str1 >> str2;

			if(map.find(str1) == map.end()) {
				map[str1] = str1;
				count[str1] = 1;
			}
			
			if(map.find(str2) == map.end()) {
				map[str2] = str2;
				count[str2] = 1;
			}

			string root1 = find(str1, map);
			string root2 = find(str2, map);
			if(root1 == root2) {
				cout << count[root1] << "\n";
			}
			else {
				merge(root1, root2, map, count);
				cout << count[root1] << "\n";
			}
		}

		test_case--;
	}

	return 0;
}