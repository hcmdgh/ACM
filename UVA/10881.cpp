#include <iostream>
#include <algorithm>
using namespace std;

const bool LEFT = false;
const bool RIGHT = true;

struct Ant {
    int pos;
    bool face;
    int idx;
    bool turning;
} ants[10005];
int indices[10005];

bool cmp1(const Ant& ant1, const Ant& ant2) {
    return ant1.pos < ant2.pos;
}

bool cmp2(const Ant& ant1, const Ant& ant2) {
    return ant1.idx < ant2.idx;
}

int main() {
    ios::sync_with_stdio(false);
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; ++q) {
        int L, T, N;
        cin >> L >> T >> N;
        for (int i = 0; i < N; ++i) {
            cin >> ants[i].pos;
            char ch;
            cin >> ch;
            ants[i].face = ch == 'L' ? LEFT : RIGHT;
            ants[i].idx = i;
        }
        sort(ants, ants + N, cmp1);
        for (int i = 0; i < N; ++i) {
            indices[i] = ants[i].idx;
            ants[i].turning = false;
            if (ants[i].face == LEFT)
                ants[i].pos -= T;
            else
                ants[i].pos += T;
        }
        sort(ants, ants + N, cmp1);
        for (int i = 0; i < N - 1; ++i) {
            if (ants[i].pos == ants[i + 1].pos)
                ants[i].turning = ants[i + 1].turning = true;
        }
//        cout << "indices:";
//        for (int i = 0; i < N; ++i) {
//            cout << indices[i] << ' ';
//        }
//        cout << endl;
        for (int i = 0; i < N; ++i) {
            ants[i].idx = indices[i];
        }
        sort(ants, ants + N, cmp2);
        cout << "Case #" << q + 1 << ":" << endl;
        for (int i = 0; i < N; ++i) {
            if (ants[i].pos < 0 || ants[i].pos > L) {
                cout << "Fell off" << endl;
            } else {
                cout << ants[i].pos << ' ';
                if (ants[i].turning)
                    cout << "Turning" << endl;
                else if (ants[i].face == LEFT)
                    cout << "L" << endl;
                else
                    cout << "R" << endl;
            }
        }
        cout << endl;
    }

    return 0;
}
