#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

int main() {
	int N;
	cin >> N;
	list<int> nums;
	for (int i = 0; i < N; ++i) {
		int input;
		cin >> input;
		nums.emplace_back(input);
	}
	nums.sort();

	int power = 0;
	for (int i = 0; i < N - 1; ++i) {
		int num1 = nums.front();
		nums.pop_front();
		int num2 = nums.front();
		nums.pop_front();
		int new_num = num1 + num2;
		power += new_num;
		auto iter = nums.begin();
		while (iter != nums.end() && *iter < new_num)
			++iter;
		nums.insert(iter, new_num);
	}

	cout << power << endl;

	return 0;
}