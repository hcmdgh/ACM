#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	string max_num;
	int max_length = 0;
	int person = -1;

	for (int i = 0; i < n; ++i) {
		string num;
		cin >> num;
		int length = num.length();
		if (length > max_length || (length == max_length && num > max_num)) {
			max_num = num;
			max_length = length;
			person = i + 1;
		}
	}
	cout << person << endl;
	cout << max_num << endl;

	return 0;
}