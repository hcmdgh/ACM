#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> Man;

vector<int> hp_divide(const vector<int>& dividend, int divisor) {
	int length = dividend.size();
	int begin_pos = length - 1;
	while (begin_pos >= 0 && dividend[begin_pos] == 0)
		--begin_pos;
	if (begin_pos < 0)
		return dividend;
}

int main() {
	ios::sync_with_stdio(false);

	int N, king_left, king_right;
	cin >> N >> king_left >> king_right;
	vector<Man> mans(N);
	for (int i = 0; i < N; ++i) {
		cin >> mans[i].first >> mans[i].second;
	}

	auto cmp = [](const Man& man1, const Man& man2) {
		return man1.first * man1.second < man2.first * man2.second;
	};
	sort(mans.begin(), mans.end(), cmp);

	return 0;
}