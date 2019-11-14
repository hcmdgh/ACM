#include <iostream>
#include <string>
using namespace std;

int main() {
	string input;
	cin >> input;
	int indexes[] = {0, 2, 3, 4, 6, 7, 8, 9, 10};
	int code = 0;
	for (int i = 0; i < sizeof(indexes) / sizeof(int); ++i) {
		code += (i + 1) * (input[indexes[i]] - '0');
	}
	code %= 11;
	char _code = code == 10 ? 'X' : code + '0';
	if (input[12] == _code)
		cout << "Right" << endl;
	else {
		input[12] = _code;
		cout << input << endl;
	}

	return 0;
}