#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
struct Farmer {
	int price, num;

	bool operator<(const Farmer& other) {
		return price < other.price;
	}
} farmers[5000];

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		cin >> farmers[i].price >> farmers[i].num;
	}

	sort(farmers, farmers + M);
	int cost = 0;
	for (int i = 0; i < M; ++i) {
		if (N >= farmers[i].num) {
			cost += farmers[i].num * farmers[i].price;
			N -= farmers[i].num;
		} else {
			cost += N * farmers[i].price;
			break;
		}
	}

	cout << cost << endl;

	return 0;
}