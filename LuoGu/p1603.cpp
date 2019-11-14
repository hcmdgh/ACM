#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	vector<pair<string, int>> _map = {
		{"one", 1},
		{"two", 2},
		{"three", 3},
		{"four", 4},
		{"five", 5},
		{"six", 6},
		{"seven", 7},
		{"eight", 8},
		{"nine", 9},
		{"ten", 10},
		{"eleven", 11},
		{"twelve", 12},
		{"thirteen", 13},
		{"fourteen", 14},
		{"fifteen", 15},
		{"sixteen", 16},
		{"seventeen", 17},
		{"eighteen", 18},
		{"nineteen", 19},
		{"twenty", 20},
		{"a", 1},
		{"both", 2},
		{"another", 3},
		{"first", 1},
		{"second", 2},
		{"third", 3},
	};

	map<string, int> str2int;
	for (const pair<string, int>& entry : _map) {
		str2int.insert(entry);
	}

	string word;
	vector<int> nums;
	while (cin >> word) {
		if (str2int.count(word)) {
			int num = str2int[word];
			nums.emplace_back(num * num % 100);
		}
	}

	if (nums.empty()) {
		cout << 0 << endl;
		return 0;
	}
	sort(nums.begin(), nums.end());
	int length = nums.size();
	char* result = new char[length * 2 + 1];
	result[length * 2] = 0;
	for (int i = 0; i < length; ++i) {
		int num = nums[i];
		int a = num / 10;
		int b = num % 10;
		char cha = a + '0';
		char chb = b + '0';
		result[i * 2] = cha;
		result[i * 2 + 1] = chb;
	}
	int begin_pos = 0;
	while (begin_pos < length * 2 && result[begin_pos] == '0')
		++begin_pos;
	if (begin_pos >= length * 2)
		cout << 0 << endl;
	else
		cout << result + begin_pos << endl;
	delete[] result;

	return 0;
}