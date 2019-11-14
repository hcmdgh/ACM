#include <iostream>
#include <string>
using namespace std;

void play(const string& records, int rounds) {
	if (records.length() == 0) {
		cout << "0:0" << endl;
		return;
	}
	int win_count = 0, lose_count = 0;
	for (char record : records) {
		if (record == 'W')
			++win_count;
		else
			++lose_count;
		if ((win_count >= rounds || lose_count >= rounds) && abs(win_count - lose_count) >= 2) {
			cout << win_count << ":" << lose_count << endl;
			win_count = lose_count = 0;
		}
	}
	cout << win_count << ":" << lose_count << endl;
}

int main() {
	string records;
	char ch;
	while ((cin >> ch) && ch != 'E') {
		records += ch;
	}

	play(records, 11);
	cout << endl;
	play(records, 21);

	return 0;
}