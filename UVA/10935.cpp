#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int N;
    while ((cin >> N) && N > 0) {
        if (N == 1) {
            cout << "Discarded cards:" << endl;
            cout << "Remaining card: 1" << endl;
            continue;
        }
        deque<int> dq;
        for (int i = 1; i <= N; ++i) {
            dq.emplace_back(i);
        }
        cout << "Discarded cards: ";
        bool first = true;
        while (dq.size() >= 2) {
            int top = dq.front();
            dq.pop_front();
            dq.emplace_back(dq.front());
            dq.pop_front();
            if (first) {
                cout << top;
                first = false;
            } else {
                cout << ", " << top;
            }
        }
        cout << endl << "Remaining card: " << dq.front() << endl;
    }

    return 0;
}
