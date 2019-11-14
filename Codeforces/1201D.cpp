#include <iostream>
using namespace std;

int N, M, K, Q;
typedef pair<int, int> Point;
Point treasures[200000];
int safe_columns[200000];

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M >> K >> Q;
    for (int i = 0; i < K; ++i) {
        cin >> treasures[i].first >> treasures[i].second;
    }
    for (int i = 0; i < Q; ++i) {
        cin >> safe_columns[i];
    }

    return 0;
}