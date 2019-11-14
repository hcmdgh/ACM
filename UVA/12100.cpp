#include <iostream>
#include <cstring>
#include <deque>
using namespace std;

int cnt[10];
deque<pair<int, int>> dq;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        dq.clear();
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < N; ++i) {
            int priority;
            cin >> priority;
            ++cnt[priority];
            dq.emplace_back(pair<int, int>(i, priority));
        }
        int t = 0;
        while (true) {
            pair<int, int> top = dq.front();
            dq.pop_front();
            int priority = top.second;
            bool canPrint = true;
            for (int i = priority + 1; i <= 9; ++i) {
                if (cnt[i] > 0) {
                    canPrint = false;
                    break;
                }
            }
            if (canPrint) {
                ++t;
                if (top.first == M) {
                    break;
                }
                --cnt[top.second];
            } else {
                dq.emplace_back(top);
            }
        }
        cout << t << endl;
    }

    return 0;
}
