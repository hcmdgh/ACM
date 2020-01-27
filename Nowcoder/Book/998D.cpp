#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int N;
map<int, int> records;

int flip(int layout, int pos) {
    layout ^= (1 << pos);
    if (pos % 5 > 0) {
        layout ^= (1 << (pos - 1));
    }
    if (pos % 5 < 4) {
        layout ^= (1 << (pos + 1));
    }
    if (pos >= 5) {
        layout ^= (1 << (pos - 5));
    }
    if (pos < 20) {
        layout ^= (1 << (pos + 5));
    }
    return layout;
}

void init() {
    queue<int> q;
    int init_state = (1 << 25) - 1;
    q.emplace(init_state);
    records[init_state] = 0;
    while (!q.empty()) {
        int state = q.front();
        q.pop();
        int step = records[state] + 1;
        if (step > 6)
            break;
        for (int i = 0; i < 25; ++i) {
            int next_state = flip(state, i);
            if (!records.count(next_state)) {
                records[next_state] = step;
                q.emplace(next_state);
            }
        }
    }
}

int readChar() {
    while (true) {
        char ch = getchar();
        if (ch == '0')
            return 0;
        if (ch == '1')
            return 1;
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    init();
    scanf("%d", &N);
    while (N--) {
        int state = 0;
        for (int i = 0; i < 25; ++i) {
            int ch = readChar();
            state |= (ch << i);
        }
        if (records.count(state)) {
            printf("%d\n", records[state]);
        } else {
            printf("-1\n");
        }
    }

    return 0;
}