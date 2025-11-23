#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
	int x, y;

	bool operator<(const Point& other) const {
		if(x == other.x) {
			y > other.y;
		}
		
		return x < other.x;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<Point> points(n);	// 0-based
	for(int i = 0; i < n; i++) {
		cin >> points[i].x >> points[i].y;
	} 

	sort(points.begin(), points.end());

	int start = points[0].x;
	int end = points[0].y;

	int total_length = 0;

	for(int i = 1; i <= n; i++) {

		if(i == n) {
			total_length += end - start;
		}

		else if(points[i].x > end) {
			total_length += end - start;

			start = points[i].x;
			end = points[i].y;
		}

		else {
			end = max(end, points[i].y);
		}
	}

	cout << total_length << "\n";

	return 0;

}