#include <iostream>
#include <algorithm>
using namespace std;

int N;
typedef pair<int, int> Pair;
Pair sticks[5000];

bool cmp(const Pair& p1, const Pair& p2) {
    return p1.first > p2.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> sticks[i].first >> sticks[i].second;
    }

    sort(sticks, sticks + N, cmp);

    int t = 0;
    for (int i = 0; i < N; ++i) {
        Pair last_pair = sticks[i];
        if (last_pair.first > -1) {
            ++t;
            for (int j = i + 1; j < N; ++j) {
                Pair& current_pair = sticks[j];
                if (current_pair.first > -1 && last_pair.second >= current_pair.second) {
                    last_pair = current_pair;
                    current_pair.first = -1;
                }
            }
        }
    }

    cout << t << endl;

    return 0;
}