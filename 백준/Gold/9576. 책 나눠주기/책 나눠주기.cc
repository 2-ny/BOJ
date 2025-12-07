#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Application {
	int start, end;
};

bool compare(const Application& a, const Application& b) {
	if(a.end == b.end) {
		return a.start < b.start;
	}
	return a.end < b.end;
}

void solution(int n, int m, vector<Application>& applications) {
	sort(applications.begin(), applications.end(), compare);

	int count_student = 0;
	vector<bool> visited(n + 1, false);

	for(int i = 0; i < m; i++) {
		int start = applications[i].start;
		int end = applications[i].end;

		for(int j = start; j <= end; j++) {
			if(!visited[j]) {
				visited[j] = true;
				count_student++;

				break;
			}
		}
	}

	cout << count_student << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int test_case;
	cin >> test_case;

	while(test_case > 0) {
		int n, m;	
		cin >> n >> m;

		vector<Application> applications(m);

		for(int i = 0; i < m; i++) {
			cin >> applications[i].start >> applications[i].end;
		}

		solution(n, m, applications);

		test_case--;
	}

	return 0;
}