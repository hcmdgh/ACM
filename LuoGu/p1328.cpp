#include <iostream>
#include <vector>
using namespace std;

const int win_map[5][5] = {
	0, -1, 1, 1, -1,
	1, 0, -1, 1, -1,
	-1, 1, 0, -1, 1,
	-1, -1, 1, 0, 1,
	1, 1, -1, -1, 0,
};

int gcd(int a, int b) {
	int r;
	while ((r = (a % b)) != 0) {
		a = b;
		b = r;
	}
	return b;
}

int main() {
	ios::sync_with_stdio(false);
	int N, Na, Nb;
	cin >> N >> Na >> Nb;
	vector<int> records_a(Na);
	vector<int> records_b(Nb);
	for (int i = 0; i < Na; ++i)
		cin >> records_a[i];
	for (int i = 0; i < Nb; ++i)
		cin >> records_b[i];
	int period = Na * Nb / gcd(Na, Nb);
	int round_score_a = 0, round_score_b = 0;
	int remaining_score_a, remaining_score_b;
	int remaining_times = N % period;
	int rounds_count = N / period;
	for (int i = 0; i < period; ++i) {
		int a = records_a[i % Na];
		int b = records_b[i % Nb];
		if (win_map[a][b] == 1) {
			++round_score_a;
		} else if (win_map[a][b] == -1) {
			++round_score_b;
		}
		if (i + 1 == remaining_times) {
			remaining_score_a = round_score_a;
			remaining_score_b = round_score_b;
		}
	}
	cout << round_score_a * rounds_count + remaining_score_a <<
		" " << round_score_b * rounds_count + remaining_score_b << endl;

	return 0;
}