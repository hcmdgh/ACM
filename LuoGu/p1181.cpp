#include <iostream>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	int sum = 0;
	int count = 1;
	for (int i = 0; i < N; ++i) {
		int input;
		cin >> input;
		sum += input;
		if (sum > M) {
			++count;
			sum = input;
		}
	}
	cout << count << endl;

	return 0;
}