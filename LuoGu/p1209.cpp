#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int M, S, C;
bool cow[201];
int gaps[201];
int gaps_cnt = 0;

int main() {
    ios::sync_with_stdio(false);
    cin >> M >> S >> C;
    for (int i = 0; i < C; ++i) {
        int id;
        cin >> id;
        cow[id] = true;
    }

    if (M >= C) {
        cout << C << endl;
        return 0;
    }

    int gap = INT_MIN;
    for (int i = 1; i <= S; ++i) {
        if (cow[i]) {
            if (gap > 0) {
                gaps[gaps_cnt++] = gap;
            }
            gap = 0;
        } else {
            gap++;
        }
    }
    for (int i = gaps_cnt; i < C - 1; ++i) {
        gaps[i] = 0;
    }

    sort(gaps, gaps + C - 1);
    int total_length = C;
    for (int i = 0; i < C - M; ++i) {
        total_length += gaps[i];
    }

    cout << total_length << endl;

    return 0;
}