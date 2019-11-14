#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<string> nums(N);
	for (int i = 0; i < N; ++i) {
		cin >> nums[i];
	}
	auto func = [](const string& str1, const string& str2) {
		return str1 + str2 > str2 + str1;
	};
	sort(nums.begin(), nums.end(), func);
	for (int i = 0; i < N; ++i) {
		cout << nums[i];
	}
	cout << endl;

	return 0;
}