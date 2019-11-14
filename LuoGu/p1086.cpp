#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
	int num;
	int i, j;

	Point(int num, int i, int j) : num(num), i(i), j(j) {}

	bool operator<(const Point& other) {
		return num < other.num;
	}
};

int main() {
	int row, column, time_limit;
	cin >> row >> column >> time_limit;
	int temp;
	vector<Point> points;
	for (int i = 1; i <= row; ++i) {
		for (int j = 1; j <= column; ++j) {
			cin >> temp;
			if (temp > 0)
				points.emplace_back(Point(temp, i, j));
		}
	}
	sort(points.rbegin(), points.rend());

	// 第一棵花生树采摘完的现状
	int current_count = points[0].num;
	int last_count = 0;
	int i = points[0].i, j = points[0].j;
	int remaining_time = time_limit - i - 1;
	auto iter = points.begin();

	while (true) {
		if (remaining_time < i) {
			cout << last_count << endl;
			break;
		}
		++iter;
		if (iter == points.end()) {
			cout << current_count << endl;
			break;
		}
		last_count = current_count;
		int delta_i = abs(i - iter->i);
		int delta_j = abs(j - iter->j);
		remaining_time -= delta_i + delta_j + 1;
		i = iter->i;
		j = iter->j;
		current_count += iter->num;
	}

	return 0;
}