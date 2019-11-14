#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> coefficients(n + 1);
	for (int i = 0; i < n + 1; ++i)
		cin >> coefficients[i];
	bool first = true;
	for (int i = 0; i < n + 1; ++i) {
		int coefficient = coefficients[i];
		int power = n - i;
		if (coefficient != 0) {
			if (coefficient >= 1 && !first)
				cout << "+";
			else if (coefficient <= -1)
				cout << "-";
			coefficient = abs(coefficient);
			if (coefficient == 1) {
				if (power == 0)
					cout << "1";
				else if (power == 1)
					cout << "x";
				else
					cout << "x^" << power;
			} else {
				if (power == 0)
					cout << coefficient;
				else if (power == 1)
					cout << coefficient << "x";
				else
					cout << coefficient << "x^" << power;
			}
			first = false;
		}
	}

	return 0;
}