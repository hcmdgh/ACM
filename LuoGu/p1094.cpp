#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int W, N;
	cin >> W >> N;
	vector<int> prices(N);
	for (int i = 0; i < N; ++i)
		cin >> prices[i];

	sort(prices.begin(), prices.end());
	int left_cur = 0, right_cur = N - 1;
	int groups = 0;
	while (left_cur <= right_cur) {
		if (prices[left_cur] + prices[right_cur] <= W) {
			++left_cur;
			--right_cur;
		} else {
			--right_cur;
		}
		++groups;
	}
	cout << groups << endl;

	return 0;
}