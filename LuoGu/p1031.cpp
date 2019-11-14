#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> piles(N);
	int average = 0;
	for (int i = 0; i < N; ++i) {
		int temp;
		cin >> temp;
		piles[i] = temp;
		average += temp;
	}
	average /= N;
	int times = 0;
	for (int i = 0; i < N - 1; ++i) {
		if (piles[i] != average) {
			++times;
			piles[i + 1] += piles[i] - average;
		}
	}
	cout << times << endl;

	return 0;
}