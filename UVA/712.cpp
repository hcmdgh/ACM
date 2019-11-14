#include <iostream>
using namespace std;

int var_order[10];
bool vars[10];
const int MAXN = (1 << 7) + 5;
bool leaves[MAXN];

int main() {
    ios::sync_with_stdio(false);
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int N, M, Q = 0;
    while ((cin >> N) && N > 0) {
        ++Q;
        for (int i = 0; i < N; ++i) {
            string var;
            cin >> var;
            int val = stoi(var.substr(1));
            var_order[val - 1] = i;
        }
        int leaves_cnt = 1 << N;
        for (int i = 0; i < leaves_cnt; ++i) {
            char ch;
            cin >> ch;
            leaves[i] = ch == '1';
        }
        cin >> M;
        cout << "S-Tree #" << Q << ":" << endl;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                char ch;
                cin >> ch;
                vars[var_order[j]] = ch == '1';
            }
            int node = 1;
            for (int j = 0; j < N; ++j) {
                if (vars[j]) {
                    node = (node << 1) ^ 1;
                } else {
                    node <<= 1;
                }
            }
            node -= leaves_cnt;
            cout << leaves[node] ? '1' : '0';
        }
        cout << endl << endl;
    }

    return 0;
}
