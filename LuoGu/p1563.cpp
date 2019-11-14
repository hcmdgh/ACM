#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	// false:����Ȧ�ڣ������±��
	// true:����Ȧ�⣬�����±���
	vector<pair<bool, string>> people(n);
	for (int i = 0; i < n; ++i) {
		cin >> people[i].first >> people[i].second;
	}
	int index = 0;
	for (int i = 0; i < m; ++i) {
		int direction, count;
		cin >> direction >> count;
		int step = ((people[index].first + direction) % 2 * 2 - 1) * (count % n);
		index += step;
		if (index >= n)
			index -= n;
		else if (index < 0)
			index += n;
	}
	cout << people[index].second << endl;

	return 0;
}