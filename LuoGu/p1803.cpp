#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<int, int>& pair1, const pair<int, int>& pair2) {
	return pair1.second < pair2.second;
}

bool overlap(const pair<int, int>& pair1, const pair<int, int>& pair2) {
	return !((pair1.first < pair2.second && pair1.second <= pair2.first) ||
		(pair2.first < pair1.second && pair2.second <= pair1.first));
}

int main() {
	int N;
	cin >> N;
	vector<pair<int, int>> times(N);
	for (int i = 0; i < N; ++i) {
		cin >> times[i].first >> times[i].second;
	}
	sort(times.begin(), times.end(), compare);
	int count = 0;
	pair<int, int>* last = nullptr;
	for (int i = 0; i < N; ++i) {
		if (last == nullptr || !overlap(*last, times[i])) {
			last = &times[i];
			++count;
		}
	}
	cout << count << endl;

	return 0;
}