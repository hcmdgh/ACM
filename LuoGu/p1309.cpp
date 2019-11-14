#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Player {
	int id;
	int score;
	int strength;

	bool operator<(const Player& other) {
		return score > other.score ||
			(score == other.score && id < other.id);
	}
};

int main() {
	ios::sync_with_stdio(false);
	int N, R, Q;
	cin >> N >> R >> Q;
	vector<Player> players(2 * N);

	for (int i = 0; i < 2 * N; ++i) {
		players[i].id = i + 1;
		cin >> players[i].score;
	}
	for (int i = 0; i < 2 * N; ++i)
		cin >> players[i].strength;

	sort(players.begin(), players.end());
	vector<Player> win_players(N);
	vector<Player> lose_players(N);
	for (int round = 0; round < R; ++round) {
		for (int i = 0; i < 2 * N; i += 2) {
			if (players[i].strength > players[i + 1].strength) {
				++players[i].score;
				win_players[i / 2] = players[i];
				lose_players[i / 2] = players[i + 1];
			} else {
				++players[i + 1].score;
				win_players[i / 2] = players[i + 1];
				lose_players[i / 2] = players[i];
			}
		}

		// ¹é²¢
		int win_cur = 0, lose_cur = 0;
		for (int i = 0; i < 2 * N; ++i) {
			if (lose_cur >= N || (win_cur < N && win_players[win_cur] < lose_players[lose_cur])) {
				players[i] = win_players[win_cur];
				++win_cur;
			} else {
				players[i] = lose_players[lose_cur];
				++lose_cur;
			}
		}
	}

	cout << players[Q - 1].id << endl;

	return 0;
}