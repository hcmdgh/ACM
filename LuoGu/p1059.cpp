#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	vector<bool> the_set(1001);
	cin >> N;
	int num;
	for (int i = 0; i < N; ++i) {
		cin >> num;
		the_set[num] = true;
	}
	int count = 0;
	for (int i = 0; i < 1001; ++i) {
		if (the_set[i])
			++count;
	}
	cout << count << endl;
	for (int i = 0; i < 1001; ++i) {
		if (the_set[i])
			cout << i << " ";
	}
	cout << endl;

	return 0;
}