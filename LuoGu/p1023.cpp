#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

bool is_optimum(const vector<int>& volumes, int expected_price, int cost, int max_price, int allowance) {
	bool valid = true;
	for (int price = cost; price <= max_price; ++price) {
		if ((expected_price - cost + allowance) * volumes[expected_price]
			< (price - cost + allowance) * volumes[price]) {
			valid = false;
			break;
		}
	}
	return valid;
}

int main() {
	vector<int> volumes(100000);

	int expected_price;
	cin >> expected_price;

	int _price, _volume;
	int cost = -1;
	int _last_price = -1;
	int max_price;
	while (true) {
		cin >> _price >> _volume;
		if (_price == -1 && _volume == -1) {
			int gap;
			cin >> gap;
			max_price = _last_price;
			_volume = volumes[_last_price] - gap;
			while (_volume > 0) {
				volumes[max_price + 1] = _volume;
				++max_price;
				_volume -= gap;
			}
			break;
		}
		if (cost == -1)
			cost = _price;
		volumes[_price] = _volume;
		if (_last_price != -1 && _price - _last_price > 1) {
			int gap = (_volume - volumes[_last_price]) / (_price - _last_price);
			for (int i = _last_price + 1; i < _price; ++i) {
				volumes[i] = volumes[i - 1] + gap;
			}
		}
		_last_price = _price;
	}

	int min_allowance = INT_MAX;
	for (int i = 0; i < 10000; ++i) {
		if (is_optimum(volumes, expected_price, cost, max_price, i)) {
			if (i < abs(min_allowance))
				min_allowance = i;
		}
		if (i != 0 && is_optimum(volumes, expected_price, cost, max_price, -i)) {
			if (i < abs(min_allowance))
				min_allowance = -i;
		}
	}
	if (min_allowance != INT_MAX)
		cout << min_allowance << endl;
	else
		cout << "NO SOLUTION" << endl;

	return 0;
}