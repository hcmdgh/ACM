#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string encrypted;
	string origin;
	cin >> encrypted >> origin;

	vector<char> the_map(26);
	vector<bool> used(26);
	int length = encrypted.length();
	for (int i = 0; i < length; ++i) {
		int encrypted_id = encrypted[i] - 'A';
		char origin_ch = origin[i];
		if (the_map[encrypted_id] != 0 && the_map[encrypted_id] != origin_ch) {
			cout << "Failed" << endl;
			return 0;
		} else if (the_map[encrypted_id] == 0) {
			if (used[origin_ch - 'A']) {
				cout << "Failed" << endl;
				return 0;
			}
			used[origin_ch - 'A'] = true;
			the_map[encrypted_id] = origin_ch;
		}
	}
	bool valid = true;
	for (char ch : the_map) {
		if (ch == 0) {
			valid = false;
			break;
		}
	}
	if (!valid) {
		cout << "Failed" << endl;
		return 0;
	}

	string message;
	cin >> message;
	for (char ch : message) {
		cout << the_map[ch - 'A'];
	}
	cout << endl;

	return 0;
}