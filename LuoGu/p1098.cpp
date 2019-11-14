#include <iostream>
#include <string>
using namespace std;

bool is_matched(char ch1, char ch2) {
	if ('0' <= ch1 && ch1 <= ch2 && ch2 <= '9')
		return true;
	if ('a' <= ch1 && ch1 <= ch2 && ch2 <= 'z')
		return true;
	if ('A' <= ch1 && ch1 <= ch2 && ch2 <= 'Z')
		return true;
	return false;
}

int main() {
	int p1, p2, p3;
	cin >> p1 >> p2 >> p3;
	string str;
	cin >> str;
	string result;
	int length = str.length();
	for (int i = 0; i < length; ++i) {
		char ch = str[i];
		if (ch != '-' || i == 0 || i == length - 1)
			result += ch;
		else {
			char begin_ch = str[i - 1];
			char end_ch = str[i + 1];
			if (is_matched(begin_ch, end_ch) && begin_ch != end_ch) {
				char _begin, _end, _step;
				if (p3 == 1) {
					_begin = begin_ch + 1;
					_end = end_ch;
					_step = 1;
				} else {
					_begin = end_ch - 1;
					_end = begin_ch;
					_step = -1;
				}
				if (p1 == 1 && begin_ch >= 'A' && begin_ch <= 'Z') {
					_begin += 32;
					_end += 32;
				} else if (p1 == 2 && begin_ch >= 'a' && begin_ch <= 'z') {
					_begin -= 32;
					_end -= 32;
				}
				for (char temp = _begin; temp != _end; temp += _step) {
					for (int j = 0; j < p2; ++j) {
						if (p1 == 3)
							result += '*';
						else 
							result += temp;
					}
				}
			} else {
				result += ch;
			}
		}
	}

	cout << result << endl;

	return 0;
}