#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> records(n);
	for (int i = 0; i < n; ++i) {
		int k, s;
		cin >> k >> s;
		records[i].first = k;
		records[i].second = s;
	}
	auto func = [](const pair<int, int>& val1, const pair<int, int>& val2) {
		if (val1.second > val2.second)
			return true;
		else if (val1.second < val2.second)
			return false;
		else
			return val1.first < val2.first;
	};
	sort(records.begin(), records.end(), func);
	int temp = m * 1.5;
	int min_score = records[temp - 1].second;
	int actual_num = temp;
	while (actual_num < n && records[actual_num].second == min_score)
		++actual_num;
	cout << min_score << " " << actual_num << endl;
	for (int i = 0; i < actual_num; ++i) {
		cout << records[i].first << " " << records[i].second << endl;
	}

	return 0;
}