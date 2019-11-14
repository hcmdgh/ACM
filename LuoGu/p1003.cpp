#include <iostream>
#include <deque>
using namespace std;

struct Carpet {
	int left, top, width, height;

	Carpet(int left, int top, int width, int height) :
		left(left), top(top), width(width), height(height)
	{}
};

int main() {
	int n;
	cin >> n;
	deque<Carpet> carpets;
	int left, top, width, height;
	for (int i = 0; i < n; ++i) {
		cin >> left >> top >> width >> height;
		carpets.push_back(Carpet(left, top, width, height));
	}
	int dest_left, dest_top;
	cin >> dest_left >> dest_top;
	int id = n;
	while (!carpets.empty()) {
		const Carpet& carpet = carpets.back();
		int x_low = carpet.left;
		int x_high = carpet.left + carpet.width;
		int y_low = carpet.top;
		int y_high = carpet.top + carpet.height;
		if (x_low <= dest_left && dest_left <= x_high &&
			y_low <= dest_top && dest_top <= y_high) {
			cout << id << endl;
			return 0;
		}
		carpets.pop_back();
		--id;
	}
	cout << -1 << endl;

	return 0;
}