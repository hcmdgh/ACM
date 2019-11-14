#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int M, N, K, L, D;
	cin >> M >> N >> K >> L >> D;
	vector<pair<int, int>> row_counts(N - 1);
	vector<pair<int, int>> column_counts(M - 1);
	for (int i = 0; i < N - 1; ++i) {
		row_counts[i].first = i + 1;
		row_counts[i].second = 0;
	}
	for (int i = 0; i < M - 1; ++i) {
		column_counts[i].first = i + 1;
		column_counts[i].second = 0;
	}
	for (int i = 0; i < D; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2) {
			++row_counts[min(y1, y2) - 1].second;
		} else {
			++column_counts[min(x1, x2) - 1].second;
		}
	}
	auto func = [](const pair<int, int> & val1, const pair<int, int> & val2) {
		return val1.second > val2.second;
	};
	auto func2 = [](const pair<int, int> & val1, const pair<int, int> & val2) {
		return val1.first < val2.first;
	};
	sort(row_counts.begin(), row_counts.end(), func);
	sort(column_counts.begin(), column_counts.end(), func);
	sort(row_counts.begin(), row_counts.begin() + L, func2);
	sort(column_counts.begin(), column_counts.begin() + K, func2);
	for (int i = 0; i < K; ++i) {
		cout << column_counts[i].first;
		if (i < K - 1)
			cout << " ";
	}
	cout << endl;
	for (int i = 0; i < L; ++i) {
		cout << row_counts[i].first;
		if (i < L - 1)
			cout << " ";
	}
	cout << endl;

	return 0;
}